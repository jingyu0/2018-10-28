/*
作业：
设计表结构
1. 确定需求及需求边界

2. 确定哪几类数据，找对象
	1. 用户
	2. 文章
	3. 评论
	4. 点赞信息
3. 找关系
	1. 用户-文章		一对多
	2. 文章-评论		一对多
	3. 用户-评论		一对多
	4. 用户-点赞-文章	多对多
4. 确定属性
	1. 用户
		1. 主键
		2. 用户名（可以重复，也可以不重复，根据需求确定）
		3. 【完善】注册时间/上次登陆时间/登陆时长/头像信息/个性签名
	2. 文章
		1. 主键
		2. 标题
		3. 作者 id
		4. 正文（TEXT)
		5. 发表时间
		6. 【冗余】点赞数量（需要程序自行保证数据的一致性）
		6. 【标签】
	3. 评论
		1. 主键
		2. 文章 id
		3. 评论者 id
		4. 评论正文(VARCHAR(100))
		5. 评论时间
	4. 点赞信息
		1. 主键
		2. 文章 id
		3. 用户 id
		4. 点赞时间
		（文章id + 用户id）唯一
5. 确定每个字段的数据类型
*/

CREATE DATABASE blog_5051;

CREATE TABLE blog_5051.users (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '自增id',
	username VARCHAR(50) UNIQUE NOT NULL COMMENT '不重复用户名'
) COMMENT '用户信息';

CREATE TABLE blog_5051.articles (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '自增id',
	author_id INT UNSIGNED NOT NULL COMMENT '作者id',
	title VARCHAR(50) NOT NULL COMMENT '标题',
	content TEXT NOT NULL COMMENT '正文',
	published_at DATETIME NOT NULL COMMENT '发表时间',
	FOREIGN KEY (author_id) REFERENCES users(id)
) COMMENT '文章信息';

CREATE TABLE blog_5051.comments (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '自增id',
	article_id INT UNSIGNED NOT NULL COMMENT '文章id',
	commenter_id INT UNSIGNED NOT NULL COMMENT '评论用户id',
	content VARCHAR(140) NOT NULL DEFAULT '' COMMENT '评论内容',
	commented_at DATETIME NOT NULL COMMENT '评论时间',
	FOREIGN KEY (article_id) REFERENCES articles(id),
	FOREIGN KEY (commenter_id) REFERENCES users(id)
) COMMENT '评论信息';

CREATE TABLE blog_5051.likes (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '自增id',
	article_id INT UNSIGNED NOT NULL COMMENT '文章id',
	liker_id INT UNSIGNED NOT NULL COMMENT '点赞用户id',
	liked_at DATETIME NOT NULL COMMENT '点赞时间',
	UNIQUE KEY (article_id, liker_id)
) COMMENT '点赞信息';

-- 1. 注册用户
-- 2. 文章列表	根据当前页码，查询出 20 条文章， 文章标题、作者、发表时间、点赞人数
--			1. 按发表时间降序排序
--			2. 按点赞人数降序排序
-- 3. 文章详情
--		1. 标题 2. 作者 3. 发表时间 4. 最近 5 个点赞的用户名称
--      5. 正文 6. 评论（按评论时间降序，一页 10 条）
-- 4. 发表文章
-- 5. 发表评论
-- 6. 点赞

-- 注册用户
#! /bin/sh

echo -n "请输入用户名: "
read username

sql="INSERT INTO blog_5051.users (username) VALUES ('${username}');"

echo "${sql}"
mysql -uroot -p123 -e "${sql}"

-- 发表文章
#! /bin/sh

echo -n "请输入标题: "
read title

echo -n "请输入作者: "
read author

echo -n "请输入正文: "
read content

published_at=`date +"%Y-%m-%d %H:%M:%S"`	# 这里是反引号

# 根据作者姓名查询用户 id
sql="SELECT id FROM blog_5051.users WHERE username = '${author}'"
author_id=`mysql -uroot -p123 -N -e "${sql}"`

# 发表文章
sql="INSERT INTO blog_5051.articles (author_id, title, content, published_at) VALUES(${author_id}, '${title}', '${content}', '${published_at}');"
mysql -uroot -p123 -N -e "${sql}"

-- 加可执行权限
chmod 755 文件名







