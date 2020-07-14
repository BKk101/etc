FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server
RUN apt-get -y install php7.3-fpm php7.3-mysql php7.3-mbstring php7.3-cli php7.3-gd php7.3-zip php7.3-curl

COPY ./srcs/ft_server.sh ./ft_server.sh
COPY ./srcs/nginx.conf ./tmp/nginx.conf
COPY ./srcs/wordpress.php ./tmp/wordpress.php
COPY ./srcs/phpmyadmin.php ./tmp/phpmyadmin.php

CMD bash ./ft_server.sh