FROM debian:buster

WORKDIR /ft_server/
COPY . .

RUN export DEBIAN_FRONTEND=noninteractive
RUN apt-get update -y

# install nginx, mysql, php, php extension
RUN apt-get install -y nginx
RUN apt-get remove mariadb-server
RUN apt-get install -y mariadb-server
RUN apt-get install -y php-fpm php-mysql
RUN apt-get install -y wget
RUN apt-get install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip


# copy certification
RUN   cp /ft_server/srcs/ssl/ft_server.crt /etc/ssl/
RUN   cp /ft_server/srcs/ssl/ft_server.key /etc/ssl/
RUN   chmod 640 /etc/ssl/ft_server.crt
RUN   chmod 640 /etc/ssl/ft_server.key

# set-up nginx (server block)
WORKDIR /ft_server/
COPY ./srcs/server_block/. /etc/nginx/sites-available/
RUN	ln -s /etc/nginx/sites-available/sb_wordpress_ai /etc/nginx/sites-enabled/
RUN unlink /etc/nginx/sites-enabled/default
RUN nginx -t
RUN service nginx restart

# install phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-english.tar.gz
RUN mkdir /var/www/html/phpmyadmin
RUN tar -xzf phpMyAdmin-4.9.0.1-english.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
RUN cp /ft_server/srcs/phpmyadmin/config.inc.php /var/www/html/phpmyadmin/

# install wordpress
WORKDIR /ft_server/srcs/wordpress/
RUN tar -xzvf latest.tar.gz
RUN cp wp-config.php ./wordpress/
RUN cp -r ./wordpress /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 80 443

ENTRYPOINT ["/bin/sh", "/ft_server/srcs/start.sh"]
