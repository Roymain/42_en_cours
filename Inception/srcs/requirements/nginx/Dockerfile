# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Romain <Romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 14:51:27 by Romain            #+#    #+#              #
#    Updated: 2022/10/05 15:01:44 by Romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

WORKDIR /app/nginx

COPY . /app

RUN apt update && apt install nginx -y && apt install openssl -y


#cryptographiques utilisées ont le format suivant :

#Pour TLS 1.2 : TLS_KE_CIPHER_HASH.
#Pour TLS 1.3 : TLS_CIPHER_HASH

EXPOSE 443

#temporaire -> interdit
CMD ["tail", "-f"]  