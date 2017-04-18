# 位于行首时表示注释。
[F] Forbidden（禁止）: 命令服务器返回 403 Forbidden错误给用户浏览器
[L] Last rule（最后一条规则）: 告诉服务器在本条规则执行完后停止重写URL
[N] Next(下一条规则): 告诉服务器继续重写，指导所有重写指令都执行过
[G] Gone（丢失）: 命令服务器返回410 GONE(no longer exists)错误消息
[P] Proxy（代理）: 告诉服务器通过mod_proxy模块处理用户请求
[C] Chain（捆绑）: 告诉服务器将当前的规则和前面的规则进行捆绑
[R] Redirect（重定向）: 命令服务器发出重定向消息，以便用户浏览器发出rewritten/modified（重写/修改）URL的请求
[NC] No Case（不区分大小写）: 对客户端请求的URL不区分大小写
[PT] Pass Through（放行）: 让mod_rewrite模块将重写的URL传回给Apache做进一步处理
[OR] Or（逻辑或）: 用逻辑“或”将两个表达式连接在一起，如果结果为“真”，则会应用后继的相关规则
[NE] No Escape（禁用转义）: 命令服务器在输出时禁用转义字符
[NS] No Subrequest（禁用子请求）: 如果存在内部子请求，则跳过当前命令
[QSA] Append Query String（追加查询字符串）: 命令服务器在URL末尾追加查询字符串
[S=x] Skip（跳过）: 如果满足某指定的条件，则跳过后面第x调规则
[E=variable:value] Environmental Variable（环境变量）: 命令服务器将值value赋给变量variable
[T=MIME-type] Mime Type（MIME类型）: 声明目标资源所属的MIME类型
[] 匹配一个字符集合，例如[xyz]可以匹配x, y或者z
[]+ 例如[xyz]+会以任何顺序、次数匹配x,y,z的出现
[^] 字符^表示字符集的补集。[^xyz]将匹配没有x,y或者z的字符串
[a-z] 连字符(-)表示匹配从字母a到字母z的所有字符串
a{n} 指定字母a出现的次数为n次，满足该条件时匹配。例如x{3}仅与xxx匹配
a{n,} 指定字母a出现的次数至少为n次，例如x{3,}可以与xxx或者xxxx等匹配
a{n,m} 指定a出现的次数至少为n到m次。
() 用于将正则表达式分组，满足第一组正则表达式的字符串会被存储在变量$1中，以此类推。如果括号中的不是正则表达式，例如(perishable)?press 将能够匹配有或者没有perishable前缀的press
^ 位于行首。注意：和中括号中的[^]意义不同。
$ 位于行末
? 例如 monzas? 会匹配 monza 或者 monzas，而 mon(za)? 会匹配 mon 或者 monza。又如 x? 会匹配“空字符” 或者 一个x
! 逻辑非。例如“!string” 将会匹配除了“string”以外的所有字符串
. 表示任意字符串
- 命令Apache“不要”重写URL，例如“xxx.domain.com.* – [F]”
+ 匹配至少一个任意字符，例如G+匹配以G开头、并且后面至少有一个字符的字符串
* 匹配零个或多个字符，例如“.*”匹配任意字符串
| 逻辑“或”，与[OR]不同的是，它只匹配字符串，例如(x|y)匹配x或者y
\ 转义字符。可以转义左括号( 尖字符^ 美元符号$ 感叹号! 点. 星号* 管道符号| 右括号) 等
\. 转义为点字符（点字符在正则表达式中可以匹配任意字符）
/* 零个或多个正斜杠
.* 零个或多个任意字符（即，匹配任意字符串，包括空字符）
^$ 匹配“空字符”、“空行”
^.*$ 匹配任意字符串（仅限一行）
[^/.] 匹配既非“正斜杠”也不是“点”的任意字符
[^/.]+ 匹配第一个字符既非“正斜杠”也不是“点”，后继字符可以是“正斜杠”或者“点”的字符串
http:// 匹配“http://”
^domain.* 匹配以“domain”开始的字符串
^domain\.com$ 仅匹配“domain.com”
-d 测试字符串是否是已存在的目录
-f 测试字符串是否是已存在的文件
-s 测试字符串所指文件是否有“非零”值

 

例一.下面是在一个虚拟主机里定义的规则。功能是把client请求的主机前缀不是www.kiya.cn和70.40.213.183都跳转到主机前缀为http://www.kiya.cn，避免相同内容的网页有多个指向的域名，如http://kiya.cn。

NameVirtualHost 70.40.213.183:80
ServerAdmin slj@kiya.cn
DocumentRoot “/web”
ServerName kiya.cn

RewriteEngine on #打开rewirte功能
RewriteCond %{HTTP_HOST} !^www.kiya.cn [NC] #声明Client请求的主机中前缀不是www.kiya.cn，其中 [NC] 的意思是忽略大小写
RewriteCond %{HTTP_HOST} !^70.40.213.183 [NC] #声明Client请求的主机中前缀不是70.40.213.183，其中 [NC] 的意思是忽略大小写
RewriteCond %{HTTP_HOST} !^$ #声明Client请求的主机中前缀不为空
RewriteRule ^(.*) http://www.kiya.cn/ [L] #含义是如果Client请求的主机中的前缀符合上述条件，则直接进行跳转到http://www.kiya.cn/,[L]意味着立即停止重写操作，并不再应用其他重写规则。这里的.*是指匹配所有URL中不包含换行字符，()括号的功能是把所有的字符做一个标记，以便于后面的应用.就是引用前面里的(.*)字符。

例二.将输入 en.sicasoft.com 的域名时跳转到www.sicasoft.com

RewriteEngine on
RewriteCond %{HTTP_HOST} ^en.sicasoft.com [NC]
RewriteRule ^(.*) http://www.sicasoft.com/ [L]

例三.赛卡软件近期更换了域名，新域名为www.sicasoft.com, 更加简短好记。这时需要将原来的域名ss.kiya.cn, 以及论坛所在地址ss.kiya.cn/bbs/定向到新的域名，以便用户可以找到，并且使原来的论坛 URL 继续有效而不出现 404 未找到，比如原来的http://ss.kiya.cn/bbs/tread-60.html, 让它在新的域名下继续有效，点击后转发到http://bbs.sicasoft.com/tread-60.html，而其他网页，如原先的http://ss.kiya.cn/purchase不会到二级域名bbs.sicasoft.com/purchase上，而是到www.sicasoft.com/purchase
按照这样的要求重定向规则应该这样写：

RewriteEngine On
RewriteCond %{REQUEST_URI} ^/bbs/
RewriteRule ^bbs/(.*) http://bbs.sicasoft.com/$1 [R=permanent,L]
RewriteCond %{REQUEST_URI} !^/bbs/
RewriteRule ^(.*) http://www.sicasoft.com/$1 [R=permanent,L]

3.Apache mod_rewrite规则重写的标志一览

1) R[=code](force redirect) 强制外部重定向
强制在替代字符串加上http://thishost[:thisport]/前缀重定向到外部的URL.如果code不指定，将用缺省的302 HTTP状态码。
2) F(force URL to be forbidden)禁用URL,返回403HTTP状态码。
3) G(force URL to be gone) 强制URL为GONE，返回410HTTP状态码。
4) P(force proxy) 强制使用代理转发。
5) L(last rule) 表明当前规则是最后一条规则，停止分析以后规则的重写。
6) N(next round) 重新从第一条规则开始运行重写过程。
7) C(chained with next rule) 与下一条规则关联

如果规则匹配则正常处理，该标志无效，如果不匹配，那么下面所有关联的规则都跳过。

8) T=MIME-type(force MIME type) 强制MIME类型
9) NS (used only if no internal sub-request) 只用于不是内部子请求
10) NC(no case) 不区分大小写
11) QSA(query string append) 追加请求字符串
12) NE(no URI escaping of output) 不在输出转义特殊字符
例如：RewriteRule /foo/(.*) /bar?arg=P1%3d$1 [R,NE] 将能正确的将/foo/zoo转换成/bar?arg=P1=zoo
13) PT(pass through to next handler) 传递给下一个处理
例如：
RewriteRule ^/abc(.*) /def$1 [PT] # 将会交给/def规则处理
Alias /def /ghi
14) S=num(skip next rule(s)) 跳过num条规则
15) E=VAR:VAL(set environment variable) 设置环境变量

4.Apache rewrite例子集合

URL重定向

例子一:
同时达到下面两个要求：
1.用http://www.zzz.com/xxx.php 来访问 http://www.zzz.com/xxx/
2.用http://yyy.zzz.com 来访问 http://www.zzz.com/user.php?username=yyy 的功能

RewriteEngine On
RewriteCond %{HTTP_HOST} ^www.zzz.com
RewriteCond %{REQUEST_URI} !^user.php$
RewriteCond %{REQUEST_URI} .php$
RewriteRule (.*).php$ http://www.zzz.com/$1/ [R]
RewriteCond %{HTTP_HOST} !^www.zzz.com
RewriteRule ^(.+) %{HTTP_HOST} [C]
RewriteRule ^([^.]+).zzz.com http://www.zzz.com/user.php?username=$1

例子二：

/type.php?typeid=* –&gt; /type*.html
/type.php?typeid=*&page=* –&gt; /type*page*.html

RewriteRule ^/type([0-9]+).html$ /type.php?typeid=$1 [PT]
RewriteRule ^/type([0-9]+)page([0-9]+).html$ /type.php?typeid=$1&page=$2 [PT]

5.使用Apache的URL Rewrite配置多用户虚拟服务器

要实现这个功能，首先要在DNS服务器上打开域名的泛域名解析（自己做或者找域名服务商做）。比如，我就把 *.kiya.us和 *.kiya.cn全部解析到了我的IP地址70.40.213.183上。

然后，看一下我的Apache中关于*.kiya.us的虚拟主机的设定。

ServerAdmin webmaster@kiya.us
DocumentRoot /home/www/www.kiya.us
ServerName dns.kiya.us
ServerAlias dns.kiya.us kiya.us *.kiya.us
CustomLog /var/log/httpd/osa/access_log.log” common
ErrorLog /var/log/httpd/osa/error_log.log”
AllowOverride None
Order deny,allow

#AddDefaultCharset GB2312

RewriteEngine on
RewriteCond %{HTTP_HOST} ^[^.]+.kiya.(cn|us)$
RewriteRule ^(.+) %{HTTP_HOST}$1 [C]
RewriteRule ^([^.]+).kiya.(cn|us)(.*)$ /home/www/www.kiya.us/sylvan$3?un=$1&%{QUERY_STRING} [L]

在这段设定中，我把*.kiya.cn和*.kiya.us 的Document Root都设定到了 /home/www/www.kiya.us

继续看下去，在这里我就配置了URL Rewrite规则。

RewriteEngine on #打开URL Rewrite功能
RewriteCond %{HTTP_HOST} ^[^.]+.kiya.(cn|us)$ #匹配条件，如果用户输入的URL中主机名是类似 xxxx.kiya.us 或者 xxxx.kiya.cn 就执行下面一句
RewriteRule ^(.+) %{HTTP_HOST}$1 [C] #把用户输入完整的地址（GET方式的参数除外）作为参数传给下一个规则，[C]是Chain串联下一个规则的意思
RewriteRule ^([^.]+).kiya.(cn|us)(.*)$ /home/www/dev.kiya.us/sylvan$3?un=$1&%{QUERY_STRING} [L]
# 最关键的是这一句，使用证则表达式解析用户输入的URL地址，把主机名中的用户名信息作为名为un的参数传给/home/www/dev.kiya.us目录下的脚本，并在后面跟上用户输入的GET方式的传入参数。并指明这是最后一条规则（[L]规则）。注意，在这一句中指明的重写后的地址用的是服务器上的绝对路径，这是内部跳转。如果使用http://xxxx这样的URL格式，则被称为外部跳转。使用外部跳转的话，浏览着的浏览器中的URL地址会改变成新的地址，而使用内部跳转则浏览器中的地址不发生改变，看上去更像实际的二级域名虚拟服务器。

 

1.重定向domain.com到www.domain.com

这种重定向旨在使域名唯一，是网站SEO必须要做的，后面重定向www.domain.com到domain.com也是出于同样的原因，只是形式不同。打开.htaccess文件，加入以下规则。(下面的规则是针对主域名的，子域名要修改)

    RewriteEngine On
    RewriteCond %{HTTP_HOST} !^www.domain.com$ [NC]
    RewriteRule ^(.*)$ http://www.domain.com/$1 [L,R=301]

2.重定向www.domain.com到domain.com

    RewriteEngine On
    RewriteCond %{HTTP_HOST} !^domain.com$ [NC]
    RewriteRule ^(.*)$ http://domain.com/$1 [L,R=301]

3.重定向olddomain.com到www.newdomain.com

    RewriteEngine On
    RewriteCond %{HTTP_HOST} !olddomain.com$ [NC]
    RewriteRule ^(.*)$ http://www.newdomain.com/$1 [L,R=301]

4.重定向olddomain.com to newdomain.com

    RewriteEngine On
    RewriteBase /
    RewriteCond %{HTTP_HOST} !olddomain.com$ [NC]
    RewriteRule ^(.*)$ http://newdomain.com/$1 [L,R=301]

5.重定向domain.com/file/file.php 到 otherdomain.com/otherfile/other.php

    RewriteCond %{HTTP_HOST} ^www.domain.com$
    RewriteRule ^file/file.php$ http://www.otherdomain.com/otherfile/other.php [R=301,L]
