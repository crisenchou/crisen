# windows 下安装mysql

---



> 安装过程

~~~
手动安装mysql
解压mysql安装包
进入到mysql的bin目录 利用mysqld install安装mysql服务
删除mysql服务 使用 mysqld  removes
利用net start mysql 启动mysql服务
最后就可以利用mysql命令进入的mysql了

~~~



> 启动过程

----

~~~
ps -ef | grep mysqld   检查mysql是否启动

cd /usr/bin

./mysqld_safe & 启动mysql

./mysqladmin -u root -p shutdown

ENTER password:*  关闭mysql

mysql -uroot -p

ENTER password:*  链接mysql服务器

show engines;显示数据库存储引擎

use database; 使用数据库

FLUSH PRIVILEGES 重新载入授权表

set names utf-8;设置字符集

show tables;显示数据表

show columns from tables;显示数据表的列名

source filepath/filename 导入数据到数据库

mysqldump   导出数据  

mysqldump -uroot -p (-d 只导出表结构) dbname (tablename  可以指定表名)> tablename.sql 

show create table tablename; 获取数据表完整结构

insert into table(column1,...) from select (column1,...) from table; 复制表
~~~






