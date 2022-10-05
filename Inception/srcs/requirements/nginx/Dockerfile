# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 14:51:27 by Romain            #+#    #+#              #
#    Updated: 2022/10/05 21:51:35 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

WORKDIR /app/nginx

COPY . /app

RUN apt update && apt install nginx -y && apt install openssl -y

RUN service nginx start

# /var/ww ->default htmltruc


#cryptographiques utilisées ont le format suivant :

#Pour TLS 1.2 : TLS_KE_CIPHER_HASH.
#Pour TLS 1.3 : TLS_CIPHER_HASH

EXPOSE 80

#temporaire -> interdit
CMD ["nginx", "-g", "daemon off;"]  