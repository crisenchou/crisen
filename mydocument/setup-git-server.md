������Լ���git������
��װ������������win7����ϵͳ+�����centos7
���������git��vitualbox��centos7����ϵͳ����

����һ����win7�Ĳ���ϵͳ�ϰ�װgit�Լ�orvale VM vitualbox����װ������
 
������������������½�����
	��win7�����¼��client���´�git bash������ssh key
ʹ��ssh-keygen ���Ȼ��һ·�س����ɣ�
	������������¼��server��ʹ��ͬ�������ssh key

Ȼ����client�аѹ�Կ�����������������Ҫ��½���û���.sshĿ¼��
ʹ���������(��Կ��Ŀ¼��~/.ssh)
scp ~/.ssh/id_rsa_pub  crisen@192.168.10.15:~/.ssh/ (ps:crisen����serverϵͳ�е��û���192.168.10.15���Ҹ�server���õ�ip��ַ����������Ҫ�����Լ���������ж�Ӧ�޸�)

����������server��ʹ��git �Cbare init ���ɷ�����git�ֿ�
��~��ǰ�û�Ŀ¼�´���my.gitĿ¼
mkdir my.git
Ȼ��Գ�ʼgit
git --bare init ./my.git(ps:һ��Ҫ���ϡ�bare�������������ɵ�git�ֿ⽫������push����)
�����ģ���client��ʹ��git clone crisen@192.168.10.15:~/my.git
Ȼ����Ŀ¼�¾�������my��Ŀ¼���������git�ֿ���
