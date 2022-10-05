# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Romain <Romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 16:27:40 by Romain            #+#    #+#              #
#    Updated: 2022/10/05 15:00:03 by Romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

WORKDIR /app/MariaDB

COPY . /app

RUN apt update && apt install mariadb-client -y && apt install mariadb-server -y 
#     &&  apt install procps -y

EXPOSE 3306


#temporaire -> interdit
CMD ["tail", "-f"]

