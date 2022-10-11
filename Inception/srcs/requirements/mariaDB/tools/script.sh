#!/bin/bash
# init database
mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

sql_file='/tmp/init_db.sql'

cat << EOF > $sql_file
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test';

alter user 'root'@'%' identified by '$MARIADB_ROOT_PWD';

CREATE DATABASE if not exists $WP_DB;
GRANT ALL PRIVILEGES ON $WP_DB.* TO '$WP_DB_USER'@'%' IDENTIFIED BY '$WP_DB_PWD';
FLUSH PRIVILEGES;
EOF

cat <<EOF >> /etc/mysql/my.cnf
[mysqld]
skip-networking=0
skip-bind-address

[mysqld_safe]
skip-networking=0
skip-bind-address
EOF

chown mysql:mysql /etc/mysql/my.cnf

# run init.sql
mysqld --user=mysql --bootstrap < $sql_file
#rm -f $sql_file

exec mysqld_safe --user=mysql