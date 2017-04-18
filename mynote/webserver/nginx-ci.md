在Nginx下通过ci框架开发项目时，发现ci框架在nginx下是不能运行的，在网 络上搜索了相关资料后可通过修改相关配置实现nginx支持PHP的ci框架。
1、修改ci框架的配置文件修 改$config['uri_protocol']值改为：$config['uri_protocol'] = 'PATH_INFO';
2、修改nginx配置文件，在SERVER段中添加如下代码：
location /index.php{
fastcgi_pass unix:/tmp/php-cgi.sock; fastcgi_param SCRIPT_FILENAME /home/wwwroot/index.php; fastcgi_param PATH_INFO $fastcgi_path_info; fastcgi_split_path_info ^(.+\.php)(.*)$;
fastcgi_param PATH_TRANSLATED $document_root$fastcgi_path_info; include fcgi.conf;
}
如果有多个应用，如：后台应用，可以多加一段以上代码，并修改相应入口文件：location /admin.php{
fastcgi_pass unix:/tmp/php-cgi.sock; fastcgi_param SCRIPT_FILENAME /home/wwwroot/admin.php;
fastcgi_param PATH_INFO $fastcgi_path_info; fastcgi_split_path_info ^(.+\.php)(.*)$;
fastcgi_param PATH_TRANSLATED $document_root$fastcgi_path_info; include fcgi.conf;
}


Ci框架配置到服务器遇到的问题
一:session储存目录，在Linux服务器上没有读写权限，解决方法是配置的时候改为数据库的方式
二:加载类的时候loader出错，原因是linux服务器对大小写敏感，切记，写程序的时候强烈要求自己注意大小写的问题
三404not found提示ngix服务器错误…解决办法未知