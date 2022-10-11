# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 14:51:27 by Romain            #+#    #+#              #
#    Updated: 2022/10/11 02:16:43 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

WORKDIR /var/www

RUN apt-get update && apt-get install nginx openssl -y

COPY conf/default /etc/nginx/sites-enabled/default

RUN mkdir -p /etc/nginx/ssl/ && \
        openssl req -x509 -nodes \
		-out /etc/nginx/ssl/rcuminal.42.fr.crt \
		-keyout /etc/nginx/ssl/rcuminal.42.fr.key \
		-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=rcuminal.42.fr/UID=rcuminal"

RUN service nginx start


#cryptographiques utilisées ont le format suivant :

#Pour TLS 1.2 : TLS_KE_CIPHER_HASH.
#Pour TLS 1.3 : TLS_CIPHER_HASH

EXPOSE 443

#temporaire -> interdit
CMD ["nginx", "-g", "daemon off;"]  