
mysql心得体会

批量修改数据表名

Select CONCAT( 'ALTER TABLE ', table_name, 'RENAME TO cms_', substring(table_name,4),';' )
FROM information_schema.tables
Where table_name LIKE 'cms%';   这个语句是把数据表中的数据组装而已  执行还需要脚本
   
phpmyadmin  有可以直接批量修改表前缀的功能


修改数据库权限
grant  revoke

grant 权限 on 数据库对象 to 用户  [identified by '密码']  
grant    all        on *.*         to crisen@'%'   identified by "password";


mysql主从配置需要从服务器版本高于主服务器
添加从服务器用户  权限是cms数据库下所有的数据表  不限制IP 
GRANT REPLICATION SLAVE ON *.* to 'slave'@'%' identified by 'slave@******';

主从复制前需要拷贝数据库

show master status; //显示主服务器状态
show slave status;//显示从服务器状态
start slave; 启动从服务器  stop slave 关闭从服务器


更改从服务器配置
change master to master_host='121.40.150.93',
master_port=3306,
master_user='slave',
master_password='slave@******',
master_log_file='mysql-bin.000007',  主服务器的日志文件名称   不是从show master status中得到的
master_log_pos=0;  这里表示从服务器要开始读取日志的位置， 从0开始表示重新复制  千万不要天蝎show master status中得到的数据   