引子：最近在一篇文章中了解到EFF(电子前哨基金会)为了推广https协议，成立了一个let'sencrypt项目，可以发放免费的证书，此证书可以被大多数主流浏览器所信任，这个邪恶的念头一爆发，就让我走上了一条坎坷的不归路

准备：
工具:certbot
环境:centOS7

获取Certbot工具：
根据我在网上了解到的信息，获取certbot工具有三种方法
第一种是通过git在github中下载
git clone https://github.com/certbot/certbot.git
第二种是通过epel-release软件源，这个软件源有许多yum中没有的软件包,包括certbot
yum install epel-release
yum install certbot
第三种是通过wget来进行下载
wget https://dl.eff.org/certbot-auto


由于钟爱github，熟悉git所有直接使用git下载好了
执行命令
git clone https://github.com/certbot/certbot.git


生成证书：
下载完了之后，会创建一个certbot的目录
cd certbot
certbot-auto certonly --standalone --email crisen@crisen.org  -d www.crisen.org
然后agree协议 静静等待生成证书即可
出现下面提示就说明安装好了
IMPORTANT NOTES:
 - Congratulations! Your certificate and chain have been saved at
   /etc/letsencrypt/live/your.domain.com/fullchain.pem. Your cert
   will expire on 20XX-09-23. To obtain a new or tweaked version of
   this certificate in the future, simply run certbot again. To
   non-interactively renew *all* of your certificates, run "certbot
   renew"
 - If you like Certbot, please consider supporting our work by:

   Donating to ISRG / Let's Encrypt:   https://letsencrypt.org/donate
   Donating to EFF:                    https://eff.org/donate-le

证书会生成在/etc/letsencrypt/live目录下

部署证书：
接着把证书的公钥和私钥配置到nginx的ssl目录下，创建软链接
ln  www.crisen.org.crt  /etc/letsencrypt/live/www.crisen.org/fullchain.pem
ln  www.crisen.org.key  /etc/letsencrypt/live/www.crisen.org/privkey.pem 
当然直接复制过去也是可行的
cp -i  www.crisen.org.crt  /etc/letsencrypt/live/www.crisen.org/fullchain.pem
cp -i  www.crisen.org.key  /etc/letsencrypt/live/www.crisen.org/privkey.pem


接下来只要配置 nginx 的https服务就可以了

效果测试：
然后进入到www.crisen.org测试一下

出现了可信任的证书 到此配置完毕

踩过的坑：
服务器操作系统版本过低：
之前我的操作系统是centOS5.1版本的，内置的python只有2.4，结果没有办法启动certbot出现，网上查看了许多文档，结果他们只告诉我certbot只支持更加现代的操作系统
解决办法：备份网站数据，升级服务器操作系统
   
