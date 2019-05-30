/**
 * 展示文章列表页
 * 1) 按发表时间的降序排列
 *    给给定参数：当前页数，从 1 开始
 *    每页 20 条文章
 */
// https://dev.mysql.com/doc/refman/8.0/en/c-api-function-overview.html
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int page = atoi(argv[1]);
    // 文章id，文章标题，发表时间，作者
    /*
     * SELECT
     *      articles.id,
     *      title,
     *      users.username,
     *      articles.published_at
     * FROM articles, users
     * WHERE articles.author_id = users.id
     * ORDER BY published_at DESC
     * LIMIT 20 OFFSET (page - 1) * 20
     */

    MYSQL *mysql = mysql_init(NULL);
    // 连接 MySQL
    mysql_real_connect(mysql,
        "127.0.0.1",   // ip 地址，写死 127.0.0.1
        "root",        // 数据库的用户名
        "123",         // 数据库的密码
        "blog_5051",   // 连接到的数据库 database
        0, NULL, 0);
    // 指定字符集编码
    mysql_set_character_set(mysql, "utf8");

    // 1. 拼接 SQL 语句
    char *sql = "SELECT \n" \
    "     articles.id, \n" \
    "     title, \n" \
    "     users.username, \n" \
    "     articles.published_at \n" \
    "FROM articles, users \n" \
    "WHERE articles.author_id = users.id \n" \
    "ORDER BY published_at DESC \n" \
    "LIMIT 20 OFFSET %d";
    char buffer[1024];
    sprintf(buffer, sql, (page - 1) * 20);
    printf("%s\n", buffer);

    // 2. 调用 MySQL C API 执行 SQL 语句
    mysql_query(mysql, buffer);
    // 3. 获取结果，进行格式化显示
    MYSQL_RES *result = mysql_store_result(mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL) {
        printf("%s, %s, %s, %s\n", row[0], row[1], row[2], row[3]);
    }
    mysql_free_result(result);

    // 关闭网络连接
    mysql_close(mysql);
}
