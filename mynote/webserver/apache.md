如何配置apache虚拟主机
首先在http.conf文件中找到# Virtual hosts
把Include conf/extra/httpd-vhosts.conf的注释去掉

可以选择更改虚拟主机所在的目录，
# Virtual hosts
#Include conf/extra/httpd-vhosts.conf
改成Include conf/extra/vhost/*  可以是任意一个目录，这样就可以加载不同目录下所有的虚拟主机了，便于不同网站的管理


当然httpd-vhosts这个文件名是可以修改的
然后需要在httpd-vhosts这个文件中加入这样的设置
<VirtualHost  *:80>
    DocumentRoot D:/wamp/www/test
    ServerName test.test.com
    DirectoryIndex index.php
</VirtualHost>
DocumentRoot 代表你的网站的绝对路径
ServerName 表示访问该服务器的域名
DirectoryIndex  路径初始文件，利用这个可以默认访问该目录下的index.php
其次在<VirtualHost  *:80> </VirtualHost>中间可以设置访问目录的权限
加入以下这样的代码
<Directory "D:/wamp/www/a">
Options FollowSymLinks
AllowOverride All
Order deny,allow
deny from all
allow from 127.0.0.1
</Directory>
表示目录访问权限，以上就表示除了本地回环地址之外，其他所有的地址都不可以访问子目录

如果是在本地测试，则需要修改hosts文件来进行测试，如果是线上的服务器，则需要解析二级域名，将域名映射到主机IP地址才能测试


Deny与Allow 选项可以对访问该服务器的ip进行限制，解决了同一局域网下，可以直接输入IP对服务器进行访问的问题
Documentroot可以对网站的路径重新设定，解决了不同项目间的切换问题



-------有时候无法解决的问题，就试试调整一下服务器配置吧