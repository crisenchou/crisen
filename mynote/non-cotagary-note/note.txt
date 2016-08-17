linux网卡配置的步骤
1. ifconfig查看当前网络情况 如果ifconfig命令不存在 则安装net-tools工具  net-tools工具在有些发行版中不是默认安装的软件
2. 配置/etc/network/interfaces 文件
3. 使用/etc/init.d/networking restart 命令重启网卡
4. 添加域名服务器 /etc/resolconf 中添加 nameserver xxx.xxx.xxx.xxx (这一步不是必须的)

在centos发行版中 使用nmtui命令可以进入到网卡设置的图形化界面进行网络配置
ifconfig命令也可以直接进行网络的配置  ifconfig 网卡名称(如:eth0,enp0s8等)  netmask 255.255.xxx.xxx broadcast xxx.xxx.xxx.xxx 但是这个命令在系统关机后就会失效  若想永久的设置  需要利用nmtui命令
nmcli命令可以查看网络情况
systemctl restart network 也可以重启网卡
ip a 可以在ifconfig无效的时候查看网络信息



GFW  Great Wall of China  防火长城
GFW是中国国家防火墙 首要设计者是北京邮电大学原校长方XX，是没办法上谷歌学习的罪魁祸首

UEFI&Legacy 是bios的两种引导方式
UEFI是新式的引到方式而legacy是传统的引导方式
UEFI只支持64位操作系统且磁盘分区必须为gpt模式


linux环境下可以使用screen软件对屏幕进行有效的控制


OSI标准七层协议，本来是作为互联网推行的标准的，但是TCP/IP协议占领的市场太大，使得TCP/IP协议成为了不是标准的标准，确切的说是，谁占领了市场谁就是标准
TCP/IP 四层体系结构 应用层 HTTP SMTP FTP 传输层 TCP UDP  网络层 IP  网络接口层ARP RARP

C/S B/S系统的区别
1. B/S 属于 C/S  浏览器是一种特殊的客户端
2. C/S系统可以使用任何通信协议 而B/S系统必须要使用HTTP协议

WSDL web service description language web服务表述语言
SOAP simple object access protocol 简单对象访问协议
REST representational state tranfer 表述型状态传递

linux 下scp命令可以跨服务器间进行文件传输，可以用来配置ssh key 配置好ssh key之后可以实现无密码的文件传输
格式为scp /path/filename  user@host:/path/filename  把本机的filename文件拷贝到远程host主机的path目录下
对应的windows的命令为ftp


node.js只是一个javascript的运行平台，采用了google chrome的浏览器的v8引擎 具备良好的性能 同时提供了很多的系统API
1. node是js的一个运行环境
2. node依赖于chrome v8引擎
3. node采用时间驱动模型
4. node有非阻塞I/O
5. node具有轻量可伸缩的特性
6. node是单进程 单线程


vagrant 是一个用于管理虚拟机的工具
vagrant box add 添加vagrant box
vagrant init 初始化vagrant box
vagrant up  启动vagrant虚拟机
vagrant ssh 登陆到虚拟机
vagrant box list 查看box列表
vagrant box remove 移除vagrant box


Bcrypt在安全性上远远大于md5等哈希函数，但是在性能上
Bcrypt加密一个密文的平均值是在68毫秒
而使用md5加密则只有0.004毫秒
性能差距约为16000倍



常见的缓存技术
1. 全页面静态化缓存
2.页面部分缓存
3.数据缓存
4.查询缓存
5.按内容变更进行缓存
6.内容式缓存
7.apache等web server缓存模块
8.PHP apc缓存扩展
9.opcache缓存


PHP在5.3.3 版本之后就自动继承了PHP-FPM 不在是第三方包 不需要在另行编译
安装的nginx服务器中 关于phpcgi的配置有两种 
一是  fastcgi-pass 127.0.0.1  这种是使用php-cgi来进行php脚本的解析
二是  fastcgi-pass unix:/run/php-fpm.sock  这种使用PHP-FPM进行解析

在ubuntu下使用ssh出现connect to host 。。。 connection refused
在ubuntu系统下 默认没有安装ssh server 
执行sudo apt-get install openssh-server安装ssh server 
然后执行/etc/init.d/ssh  start



