/* 一对一、一对多、多对多 */

-- 老师表

CREATE TABLE teachers (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL
);

CREATE TABLE classes (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL
);

CREATE TABLE students (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL,
	class_id INT NOT NULL,
	FOREIGN KEY (class_id) REFERENCES classes(id)
);

SELECT LAST_INSERT_ID();

INSERT INTO classes (name) VALUES ('比特50班'), ('比特51班');
INSERT INTO students (name, class_id) VALUES
('小A', 2),
('小B', 1);

DELETE FROM classes WHERE name = '比特50班'; -- 会失败

DELETE FROM students WHERE name = '小B';
DELETE FROM classes WHERE name = '比特50班'; -- 会成功

-- MySQL 不建议使用外键


CREATE TABLE goods (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '',
	name VARCHAR(30) NOT NULL COMMENT '',
	price INT NOT NULL COMMENT '单位是分',
	category VARCHAR(20) NOT NULL DEFAULT '' COMMENT '',
	provider VARCHAR(50) NOT NULL DEFAULT '' COMMENT ''
) COMMENT '商品信息';

CREATE TABLE customers (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '',
	name VARCHAR(20) NOT NULL COMMENT '',
	address VARCHAR(100) COMMENT '',
	email VARCHAR(100) COMMENT '',
	gender TINYINT NOT NULL COMMENT '0 保密 1 女 2 男',
	idcard CHAR(18) NOT NULL COMMENT '实名制'
) COMMENT '客户信息';

CREATE TABLE purchases (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '',
	customer_id INT UNSIGNED NOT NULL COMMENT '',
	goods_id INT UNSIGNED NOT NULL COMMENT '',
	num INT NOT NULL DEFAULT 0 COMMENT '',
	FOREIGN KEY (customer_id) REFERENCES customers(id),
	FOREIGN KEY (goods_id) REFERENCES goods(id)
) COMMENT '订单信息';

/*
博客系统
1. 用户管理
2. 每个用户都有权限发文章
	1. 标题、作者、发文时间、正文
3. 每篇文章，每个用户都有权限去评论
	1. 评论者、关联文章、评论信息、评论时间
4. 每个用户都可以点赞某一篇文章
	1. 谁 点赞 哪篇文章
*/

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



















