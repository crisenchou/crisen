��Nginx��ͨ��ci��ܿ�����Ŀʱ������ci�����nginx���ǲ������еģ����� ����������������Ϻ��ͨ���޸��������ʵ��nginx֧��PHP��ci��ܡ�
1���޸�ci��ܵ������ļ��� ��$config['uri_protocol']ֵ��Ϊ��$config['uri_protocol'] = 'PATH_INFO';
2���޸�nginx�����ļ�����SERVER����������´��룺
location /index.php{
fastcgi_pass unix:/tmp/php-cgi.sock; fastcgi_param SCRIPT_FILENAME /home/wwwroot/index.php; fastcgi_param PATH_INFO $fastcgi_path_info; fastcgi_split_path_info ^(.+\.php)(.*)$;
fastcgi_param PATH_TRANSLATED $document_root$fastcgi_path_info; include fcgi.conf;
}
����ж��Ӧ�ã��磺��̨Ӧ�ã����Զ��һ�����ϴ��룬���޸���Ӧ����ļ���location /admin.php{
fastcgi_pass unix:/tmp/php-cgi.sock; fastcgi_param SCRIPT_FILENAME /home/wwwroot/admin.php;
fastcgi_param PATH_INFO $fastcgi_path_info; fastcgi_split_path_info ^(.+\.php)(.*)$;
fastcgi_param PATH_TRANSLATED $document_root$fastcgi_path_info; include fcgi.conf;
}


Ci������õ�����������������
һ:session����Ŀ¼����Linux��������û�ж�дȨ�ޣ�������������õ�ʱ���Ϊ���ݿ�ķ�ʽ
��:�������ʱ��loader����ԭ����linux�������Դ�Сд���У��мǣ�д�����ʱ��ǿ��Ҫ���Լ�ע���Сд������
��404not found��ʾngix���������󡭽���취δ֪