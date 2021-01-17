#!/bin/bash

# nginx start
service nginx start;
service nginx status;

# SSL key-generate
openssl req -newkey rsa:4096 -nodes -x509 -keyout localhost.dev.key -out localhost.dev.crt -days 365 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=Sunhpark/CN=localhost";
mv localhost.dev.crt etc/ssl/certs/;
mv localhost.dev.key etc/ssl/private/;
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key;

mv ./srcs/nginx_setting_default ./etc/nginx/sites-available/default;

service php7.3-fpm start;
service php7.3-fpm status;

mv ./srcs/phpinfo.php ./var/www/html/

service nginx reload;

# phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html
rm phpMyAdmin-5.0.2-all-languages.tar.gz
mv ./srcs/config.inc.php ./var/www/html/phpmyadmin/config.inc.php

service nginx reload
service mysql start
service php7.3-fpm restart

# mysql build table
mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysql < ./srcs/wordpress.sql -u root --skip-password

service mysql start
service nginx reload

# wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress var/www/html
chown -R www-data:www-data /var/www/html/wordpress

mv ./srcs/wp-config.php var/www/html/wordpress/

service nginx reload
