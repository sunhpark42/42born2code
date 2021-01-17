# debian:buster image 를 docker hub에서 가져오기.
FROM debian:buster

MAINTAINER FT_SERVER "sunhpark@student.42seoul.kr"

COPY . .

# Package manager vesion update
RUN apt-get update -y
RUN apt-get upgrade -y

# nginx 설치
RUN apt-get install -y nginx

# SSL key
RUN apt-get install -y openssl

# php-fpm
RUN apt-get install -y php-fpm

# MySQL, phpmyadmin
RUN apt-get install -y mariadb-server php-mysql
RUN apt-get install -y wget

# RUN init shell
RUN ./srcs/init.sh

RUN rm -rf ./srcs/*

EXPOSE 80
EXPOSE 443

CMD service nginx start; service mysql start; service php7.3-fpm start; bash;

