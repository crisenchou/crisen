���ӣ������һƪ�������˽⵽EFF(����ǰ�ڻ����)Ϊ���ƹ�httpsЭ�飬������һ��let'sencrypt��Ŀ�����Է�����ѵ�֤�飬��֤����Ա��������������������Σ����а�����ͷһ������������������һ�������Ĳ���·

׼����
����:certbot
����:centOS7

��ȡCertbot���ߣ�
�������������˽⵽����Ϣ����ȡcertbot���������ַ���
��һ����ͨ��git��github������
git clone https://github.com/certbot/certbot.git
�ڶ�����ͨ��epel-release���Դ��������Դ�����yum��û�е������,����certbot
yum install epel-release
yum install certbot
��������ͨ��wget����������
wget https://dl.eff.org/certbot-auto


�����Ӱ�github����Ϥgit����ֱ��ʹ��git���غ���
ִ������
git clone https://github.com/certbot/certbot.git


����֤�飺
��������֮�󣬻ᴴ��һ��certbot��Ŀ¼
cd certbot
certbot-auto certonly --standalone --email crisen@crisen.org  -d www.crisen.org
Ȼ��agreeЭ�� �����ȴ�����֤�鼴��
����������ʾ��˵����װ����
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

֤���������/etc/letsencrypt/liveĿ¼��

����֤�飺
���Ű�֤��Ĺ�Կ��˽Կ���õ�nginx��sslĿ¼�£�����������
ln  www.crisen.org.crt  /etc/letsencrypt/live/www.crisen.org/fullchain.pem
ln  www.crisen.org.key  /etc/letsencrypt/live/www.crisen.org/privkey.pem 
��Ȼֱ�Ӹ��ƹ�ȥҲ�ǿ��е�
cp -i  www.crisen.org.crt  /etc/letsencrypt/live/www.crisen.org/fullchain.pem
cp -i  www.crisen.org.key  /etc/letsencrypt/live/www.crisen.org/privkey.pem


������ֻҪ���� nginx ��https����Ϳ�����

Ч�����ԣ�
Ȼ����뵽www.crisen.org����һ��

�����˿����ε�֤�� �����������

�ȹ��Ŀӣ�
����������ϵͳ�汾���ͣ�
֮ǰ�ҵĲ���ϵͳ��centOS5.1�汾�ģ����õ�pythonֻ��2.4�����û�а취����certbot���֣����ϲ鿴������ĵ����������ֻ������certbotֻ֧�ָ����ִ��Ĳ���ϵͳ
����취��������վ���ݣ���������������ϵͳ
   
