1. 도커 설치 (도커 docs)

2. wget http://nginx.org/keys/nginx_signing.key
   apt-key add nginx_signing.key

   sudo apt update
   apt-get install -y nginx // 엔진엑스 설치

5. sudo apt install mysql-server //mysql설치

6. sudo apt install php-fpm php-mysql //php 설치

7. /etc/nginx/sites-available // nginx php & ssl 사용가능케하기

8. /etc/nginx/sites-enable에 ln -s 심볼릭링크 추가하기

7. phpmyadmin 설치 & 설정

8. sties-enable에 default unlink하기

9. sudo systemctl reload nginx // nginx 다시 시작

10. 워드프레스 파일 받아서 압축풀어주기 -> 복붙

11.  sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt // ssl 작업

