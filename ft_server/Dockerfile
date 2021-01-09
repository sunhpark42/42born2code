# debian:buster image 를 docker hub에서 가져오기.
FROM debian:buster

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

