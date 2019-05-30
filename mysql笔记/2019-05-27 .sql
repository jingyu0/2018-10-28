/*
 1. 建表
	1. 表之间的关系
		1. 一对一、一对多、多对多
		2. 如何建表实现三种关系
			多对多的关系需要中间表
			客户-商品	多对多 中间（订单表）
		3. 如何设计表（重点）
			1. 确定需求
			2. 找对象（明确的实体）
			3. 找关系
			4. 确定属性
			5. 确定属性类型及其他约束
			6. 可以有优化的进阶部分
		4. 外键（了解）
 2. 增删改查（重点中的重点）	（DML）
	1. 插入
		INSERT INTO 表名 [(指定列)] VALUES (值列) [, ...];	95%
		
		INSERT INTO ... ON DUPLICATE UPDATE ...
		REPLACE INTO ...
	2. 查询（重点）
		SELECT * | 字段名 | 表达式 | 函数	-- 列做筛选
		FROM 表名 | 多表 | 临时表
		WHERE 逻辑运算表达式				-- 行做筛选
		ORDER BY ASC | DESC 				-- 没有 ORDER BY 都是无序
		LIMIT ...
	3. 更新
		UPDATE 表名 SET 字段 = xxx, 字段2 = xxx WHERE ...;
	4. 删除
		1. DELETE FROM 表名 WHERE ...;
		2. TRUNCATE 表名;			-- 直接把表截断	（DDL），生产环境不用
 */
 
 /*
 1. 从 表1 查询数，插入到表2 
 */
CREATE TABLE source_table (
	id INT,
	name VARCHAR(30)
);
 
CREATE TABLE dest_table (
	id INT,
	name VARCHAR(30),
	gender CHAR(1)
);

INSERT INTO source_table VALUES (1, '小A'), (2, '小B'), (3, '小C');
-- 把 id >= 2 的数据，插入到 dest_table
INSERT INTO dest_table (id, name, gender) 
SELECT id, name, '男' FROM source_table WHERE id >= 2;
 
/* 最常见的应用常见，了解
有一张表，已经在生成环境使用
需要更改这表的表结构，添加一列（操作非常慢，基本要 10 分钟）
这 10 分钟，这张表无法使用，不可以接收

1. 根据老的表结构，新建一张新表
2. 直接修改新表的结构，里头没有数据，所以很快
3. INSERT .. SELECT ... 从老表中把数据导入到新表
4. 补下期间漏掉的数据
5. RENAME TABLE old_table TO backup_20190527, new_table TO old_table;	// 原子

*/

-- 根据 old_table 的表结构，新建 new_table
CREATE TABLE new_table LIKE old_table;

/*
 聚合查询
 */
 
-- { 1, 2, 3, 4 }		平均值 | 最大值 | 总和
SELECT COUNT(1) -- 求数量 90%
-- COUNT(*) 不用管 NULL
-- COUNT(字段) 	字段的值是 NULL，不计算

/*
 分组聚合
 1. SELECT 后边 只能跟 1. 出现在 GROUP BY 后的字段 2. 聚合函数
 2. GROUP BY 后可以出现多个字段
 3. 不要混淆 GROUP BY 和 ORDER BY
 */
SELECT deptno, name, COUNT(*) FROM emp GROUP BY deptno;
SELECT deptno, MAX(sal) FROM emp GROUP BY deptno;

SELECT deptno, job, COUNT(*) FROM emp WHERE sal > 800 GROUP BY deptno, job;

-- 在分组聚合的查询结果上继续过滤
-- 在结果上做过滤，把结果看成一张表
-- 1. HAVING 不要和 WHERE 弄混
-- HAVING 在分组后过滤，WHERE 在分组前过滤
SELECT deptno, job, COUNT(*) FROM emp 
WHERE sal > 800
GROUP BY deptno, job
HAVING COUNT(*) > 2;
 
/*
 关于 MySQL 和 Oracle 的区别
 
 MySQL 做计算比较差，把 MySQL 完全当存储，一点计算的操作不要放到 MySQL 上进行
*/ 
 
-- IFNULL(val1, val2) 		val1 is not null ? val1 : val2
-- NULLIF(val1, val2)		val1 == val2 ? NULL : val1

/*
连表查询（多表查询）	重点
*/

/*
部门有 4 个			10、20、30、40
员工所在部门有 3 个	10、20、30

如果没有指定条件，查询出数量是笛卡儿积关系	表1的数量 * 表2的数量
*/

/*
内联查询
	SELECT ... FROM 表1, 表2  WHERE 表1.id = 表2.class_id;
	SELECT ... FROM 表1 [INNER] JOIN 表2 ON 表1.id = 表2.class_id WHERE ...;
外联查询
	1. 左外联
	SELECT ... FROM 表1 LEFT JOIN 表2 ON 表1.id = 表2.class_id;
	2. 右外联
	SELECT ... FROM 表1 RIGHT JOIN 表2 ON 表1.id = 表2.class_id;
	3. 全外联
*/

CREATE TABLE classes (
	id INT,
	name VARCHAR(30)
);

CREATE TABLE students (
	id INT,
	class_id INT,
	name VARCHAR(30)
);

INSERT INTO classes (id, name)
VALUES (1, '50班'), (2, '51班'), (3, '52班');

INSERT INTO students (id, class_id, name) VALUES
(100, 1, 'A'), (200, 1, 'B'),(300, 1, 'C'),(400, 1, 'D'),
(500, 2, 'E');

SELECT classes.name, students.name FROM classes, students 
WHERE classes.id = students.class_id AND classes.name = '50班';
 
/* 子查询：查询结果作为 1. 条件 2. 新的表 重新查询 */
-- 子查询必须被小括号包起来 重点

-- 查询出和 SMITH 同一部门的员工
-- 查询出 SMITH 所处部门	
SELECT deptno FROM emp WHERE ename = 'SMITH';
-- 查询部门编号是 20 的所有员工
SELECT deptno, ename FROM emp WHERE deptno = 20;
-- 连起来
SELECT deptno, ename FROM emp 
WHERE deptno = (SELECT deptno FROM emp WHERE ename = 'SMITH');

/*
1. 作为条件
	1. 结果是单行单列
	2. 结果是多行单列
		1. IN ()
		2. ALL ()
		3. ANY ()
	3. 结果是单行多列
		(字段1, 字段2, ...) = (子查询)	用 AND 组合
		
2. 作为结果二次查询
	放在 FROM 后，必须给出别名
*/


/*	查询		98%
1. 基本查询
2. 聚合查询
3. 分组查询
4. 联表查询
5. 子查询
6. 合并查询	了解
*/










 
 
 