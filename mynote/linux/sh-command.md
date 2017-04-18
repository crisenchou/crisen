linux环境下使用ssh命令可以远程链接到计算机，
命令如下
ssh -1 user@ip ssh是命令 -1是ssh协议版本 也可以使用-2  user表示同户名加上@符号后面的IP地址
如果连接成功，系统会提示你输入密码，然后输入密码之后，则成功进入对方计算机
使用此方法可以不借助于xshell壳来进行服务器的远程控制

ssh-keygen -t rsa -C "269298762@qq.com"  生成ssh密钥   -t 密钥类型   -C 用户邮箱
ssh-keygen 可以生成ssh密钥
-t rsa  密钥类型
-C 密钥注释
-f 文件名
-N 密钥密码  --help查看帮助文档