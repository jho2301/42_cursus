#!/bin/sh

service php7.3-fpm start
service mysql restart
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "CREATE USER 'wordpressuser'@'localhost' IDENTIFIED BY '0000';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpressuser'@'localhost';" | mysql -u root 
echo "FLUSH PRIVILEGES;" | mysql -u root
service nginx restart
/bin/sh