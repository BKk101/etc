service mysql start

chown -R www-data /var/www/*
chmod -R 755 /var/www/*

mkdir /var/www/jungtlee && touch /var/www/jungtlee/index.php
echo "<?php phpinfo(); ?>" >> /var/www/jungtlee/index.php

mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/jungtlee.pem -keyout /etc/nginx/ssl/jungtlee.key -subj "/C=KR/ST=Seoul/O=42Seoul/OU=jungtlee/CN=lee"

mv ./tmp/nginx.conf /etc/nginx/sites-available/jungtlee
ln -s /etc/nginx/sites-available/jungtlee /etc/nginx/sites-enabled/jungtlee
rm -rf /etc/nginx/sites-enabled/default

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root —skip-password
echo "UPDATE mysql.user set plugin='mysql_native_password' WHERE user='root';" | mysql -u root —skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root —skip-password

mkdir /var/www/jungtlee/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz —strip-components 1 -C /var/www/jungtlee/phpmyadmin
mv ./tmp/phpmyadmin.php /var/www/jungtlee/phpmyadmin/config.inc.php

cd /tmp/
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/jungtlee/
mv /tmp/wordpress.php /var/www/jungtlee/wordpress/wp-config.php

service php7.3-fpm start

service nginx start

bash