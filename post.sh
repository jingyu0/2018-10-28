#! /bin/sh

echo -n "请输入标题: "
read title

echo -n "请输入作者: "
read author

echo -n "请输入正文: "
read content

published_at=`date +"%Y-%m-%d %H:%M:%S"`

# 根据作者姓名查询用户 id
sql="SELECT id FROM blog_5051.users WHERE username = '${author}'"
author_id=`mysql -uroot -p123 -N -e "${sql}"`

# 发表文章
sql="INSERT INTO blog_5051.articles (author_id, title, content, published_at) VALUES(${author_id}, '${title}', '${content}', '${published_at}');"
mysql -uroot -p123 -N -e "${sql}"