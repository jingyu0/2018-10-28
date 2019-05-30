/*
查询	语法	90%
1. 基本查询
SELECT 			列的筛选
FROM 			表、多表、子查询
WHERE 			行的筛选
GROUP BY 		分组字段，可以有多个
HAVING 			在分组后的结果上，再次左行筛选
ORDER BY		结果排序
LIMIT 			最后切片

2. 聚合查询
COUNT(*)		最主要
MAX | MIN | SUM | AVG 

3. 分组（聚合）查询(***)
GROUP BY		可以多个字段分组，SELECT 后出现的只能是 GROUP BY 字段或者聚合函数
HAVING			所有的 HAVING 都可以转换为子查询的形式

4. 联/连表查询(***)	A	B
	1. 内联查询		（返回交集 A 交集 B）
		1. FROM A, B WHERE A.id = B.id;
		2. FROM A [INNER] JOIN B ON A.id = B.id;
	2. 外联查询
		1. 左联		返回以 A 为基准
		FROM A LEFT [OUTTER] JOIN B ON ...
		2. 右联		返回以 B 为基准
		FROM A RIGHT JOIN B ON ...
		3. 全联		A 并集 B	（MySQL 不支持）
5. 子查询
	所有子查询必须用小括号括起来
	1. WHERE 子句
		1. 结果是单行单列 
		2. 结果是多行单列 IN/ALL/ANY 
		3. 结果是单行多列 (字段1, 字段2, ...) = (子查询)	用 AND
	2. FROM 子句
		把结果看作临时表，再次查询
		1. 必须起别名
6. 联合查询
	1. UNION			会去重相同项
	2. UNION ALL
** MySQL 是个老头，别让他干活	
*/

/*
1. 索引（INDEX），用来提升查询效率的一类数据结构，保存在磁盘上。
2. 能提供搜索的功能的数据结构
	1. 平衡搜索树，B+树，应用较多
	2. 哈希表
3. 索引的工作原理
4. 为什么要用B+树，不用二叉搜索树
	1. B+树，是多叉树，所以同等情况下，高度更低
	2. 数据库文件保存在磁盘上，IO特别慢
	3. 高度越高，磁盘IO次数越多
5. 搜索树和哈希表的优缺点
	1. 搜索树		有序性
	2. 哈希表		快
	
	id, name, idcard		复合索引(name, idcard)
	1. 利用有序性
	SELECT * FROM 表 WHERE name > 'A' AND name < 'Z';	范围查找
	SELECT * FROM 表 ORDER BY name;						结果排序
	SELECT * FROM 表 ORDER BY name = 'xxx';
	2. 单个查找
	SELECT * FROM 表 WHERE name = 'A';
6. MySQL 支持的索引
	1. 主键
	2. 唯一键
	3. 普通索引	应用最多
	4. 全文索引（了解）	不支持中文	了解）	Solr/Sphinx 搜索引擎	
7. 索引的优点和缺点
	1. 查找快
	2. 多耗空间 | 修改变慢
8. 索引的适用场景
	读多写少
*/



SELECT * FROM EMP WHERE empno = 998877;	-- 很慢
EXPLAIN SELECT * FROM EMP WHERE empno = 998877;	-- rows 大概 800万
ALTER TABLE EMP ADD INDEX(empno);		-- 修改表，添加索引在 empno 字段1
SELECT * FROM EMP WHERE empno = 998877;	-- 很快
EXPLAIN SELECT * FROM EMP WHERE empno = 998877;	-- rows 为 1



CREATE TABLE accounts (
	name VARCHAR(20) COMMENT '姓名',
	balance INT COMMENT '存款'
);

START TRANSACTION;
INSERT INTO accounts VALUES ('孙悟空', 10000);
SAVEPOINT swk;
SELECT * FROM accounts;
INSERT INTO accounts VALUES ('唐三藏', 20000);
SAVEPOINT tsz;
SELECT * FROM accounts;
INSERT INTO accounts VALUES ('猪八戒', 30000);
SAVEPOINT zbj;
SELECT * FROM accounts;

ROLLBACK TO swk; -- 只剩孙悟空
SELECT * FROM accounts;
ROLLBACK;		 -- 事务什么都没干
SELECT * FROM accounts;




CREATE TABLE students (
	id INT PRIMARY KEY,
	name CHAR(30),
	INDEX(name)
);

-- 查看一张表有的索引
SHOW INDEX FROM 表名;

-- 调优查询语句时用的，重要！！！	重点看 rows 列
EXPLIAN SELECT * FROM 表 WHERE name = 'A';

-- 如何调优查询【扩展了解】
-- 1. 通过 EXPLAIN 看有没有命中索引
-- 2. 如果没有命中，修改到命中索引


-- 事务
CREATE TABLE tickets (
	checi VARCHAR(20) UNIQUE COMMENT '车次',
	num INT	COMMENT '所剩票数'
)	'余票';


-- 并发的环境下工作
-- 票只剩 1 张

/*
买票，应该是原子，中间不能被打断，不能插入其他语句 {
	SELECT num FROM tickets WHERE checi = 'D2009';
	if (num) {
		UPDATE tickets SET num = num - 1 WHERE checi = 'D2009';
	}
}

事务就是把一组 SQL，组成一套原子的操作

商务系统，电商（超卖问题）
*/

START TRANSACTION;	-- 开启事务
SELECT num FROM tickets WHERE checi = 'D2009';
UPDATE tickets SET num = num - 1 WHERE checi = 'D2009';
COMMIT;		-- 成功，提交

ROLLBACK;	-- 失败，回滚
ROLLBACK `point_name`;  -- 回滚到指定存档
SAVEPOINT `point_name`;	-- 存档

/*
1. 四个特性	ACID（原子性/一致性/隔离性/持久性）
2. 隔离级别
	1. 四个隔离级别
		1. 读未提交/读已提交/可重复读/可串行化
	2. 三个问题
		1. 脏读/不可重复读/幻读
*/

CREATE TABLE salaries (
	name VARCHAR(20),
	salary INT
);

INSERT INTO salaries VALUES ('猪八戒', 10000), ('孙悟空', 20000),
('唐三藏', 15000), ('沙悟净', 8000);



/* 统一总结
1. 语法
	DDL	了解
		CREATE DATABASE ... | SHOW DATABASE | ...
		CREATE TABLE ... | SHOW TABLES | ...
		隐含着约束、指定索引
	DML 掌握
		1. INSERT | UPDATE | DELETE 基本掌握
		2. SELECT 重点掌握
2. 理论
	1. 引擎的差别（MyISAM vs InnoDB）
	2. 索引的理论
	3. 事务（ACID/隔离级别/三个问题）
3. 扩展性问题
	1. 给定一个业务场景，建表
	2. 难点，给定一个查询，比较慢，如何优化
4. 个人期望
	1. 可以在比特的项目中把 MySQL 用起来
*/


	
	
	
	
	