#! /bin/sh

echo -n "请输入用户名: "
read username

sql="INSERT INTO blog_5051.users (username) VALUES ('${username}');"

echo "${sql}"
mysql -uroot -p123 -e "${sql}"