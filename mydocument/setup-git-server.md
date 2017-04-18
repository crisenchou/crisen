搭建属于自己的git服务器
安装环境：宿主机win7操作系统+虚拟机centos7
所需软件：git，vitualbox，centos7操作系统镜像

步骤一：在win7的操作系统上安装git以及orvale VM vitualbox，安装过程略
 
步骤二：配置无密码登陆虚拟机
	在win7（以下简称client）下打开git bash，生成ssh key
使用ssh-keygen 命令，然后一路回车即可，
	在虚拟机（以下简称server）使用同样命令创建ssh key

然后在client中把公钥拷贝到虚拟机的所需要登陆的用户的.ssh目录下
使用以下命令，(公钥的目录在~/.ssh)
scp ~/.ssh/id_rsa_pub  crisen@192.168.10.15:~/.ssh/ (ps:crisen是我server系统中的用户，192.168.10.15是我给server配置的ip地址，这两处需要根据自己的情况进行对应修改)

步骤三：在server中使用git –bare init 生成服务器git仓库
在~当前用户目录下创建my.git目录
mkdir my.git
然后对初始git
git --bare init ./my.git(ps:一定要带上—bare参数，否则生成的git仓库将不允许push数据)
步骤四：在client中使用git clone crisen@192.168.10.15:~/my.git
然后在目录下就生成了my的目录，里面就是git仓库了
