
mysql�ĵ����

�����޸����ݱ���

Select CONCAT( 'ALTER TABLE ', table_name, 'RENAME TO cms_', substring(table_name,4),';' )
FROM information_schema.tables
Where table_name LIKE 'cms%';   �������ǰ����ݱ��е�������װ����  ִ�л���Ҫ�ű�
   
phpmyadmin  �п���ֱ�������޸ı�ǰ׺�Ĺ���


�޸����ݿ�Ȩ��
grant  revoke

grant Ȩ�� on ���ݿ���� to �û�  [identified by '����']  
grant    all        on *.*         to crisen@'%'   identified by "password";


mysql����������Ҫ�ӷ������汾������������
��Ӵӷ������û�  Ȩ����cms���ݿ������е����ݱ�  ������IP 
GRANT REPLICATION SLAVE ON *.* to 'slave'@'%' identified by 'slave@******';

���Ӹ���ǰ��Ҫ�������ݿ�

show master status; //��ʾ��������״̬
show slave status;//��ʾ�ӷ�����״̬
start slave; �����ӷ�����  stop slave �رմӷ�����


���Ĵӷ���������
change master to master_host='121.40.150.93',
master_port=3306,
master_user='slave',
master_password='slave@******',
master_log_file='mysql-bin.000007',  ������������־�ļ�����   ���Ǵ�show master status�еõ���
master_log_pos=0;  �����ʾ�ӷ�����Ҫ��ʼ��ȡ��־��λ�ã� ��0��ʼ��ʾ���¸���  ǧ��Ҫ��Ыshow master status�еõ�������   