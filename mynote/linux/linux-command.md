ls显示目录  ll显示目录所有内容
cd进入目录
mkdir创建目录
uname -a显示系统信息
history  显示历史命令 -c清除历史命令
vim  打开文本文件，不存在则创建
cat  用文本形式输出文件
more 用文本形式输出文件 可以使用正则表达式
rm   删除文件   //rm -rf 目录名 删除文件夹以及文件夹下所有文件
rmdir  删除目录
clear清屏
cp 文件所在目录/文件名  目标位置目录  //复制文件
mv移动文件
useradd 用户名 //添加一个用户
passd 用户名 //给用户名设置密码 此时系统会弹出提示输入密码
userdel  用户名  //删除一个用户
su 用户名  //切换用户
groupadd 组名  //添加用户组
groupdel 组名 //删除用户组
chown   更改文件或目录 所属用户和用户组
chmod 更改文件或者目录权限

id 用户名 //查看用户以及用户所在的组别信息
man  可以查看命令的使用方法
usermod -g 组名 用户名  //修改用户所在的组别  覆盖性
usermod -G 组名,组名,组名  用户名  //给用户修改到多个组别
在linux系统中  ^表示通配符开始 $通配符结束
tar 解压tar文件 参数待续
ping 测试目标地址的可链接性
wget 下载文件
pwd查看当前所在的完整路径
ps 查看进程
telnet命令可以用来检测端口，linux下用.sh脚本输入telnet命令可以编写简易扫描工具
awk工具 awk '{print $1}' filename
sed工具 可以过滤输出 看起来是删除 但实际上并没有删除原文件
xargs 使用管道组合命令时 使用xargs可以接收前面的命令产生的输出  -i 参数表示可以用{}进行参数的填充
last 命令可以查看所有登陆计算机的用户的情况

tail命令可以返回文件的最后多少行 tail -n 100 file

w3m命令可以查看网页
screen命令可以管理屏幕



linux下访问windows的共享文件

sudo mount -t cifs -o username=xxx,password=xxx   //ip address/filename  /mnt/win/



