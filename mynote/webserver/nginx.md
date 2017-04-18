nginx对windows不是很友好 但是大多数功能还是比较完善的   

nginx不能解析php 需要使用phpcgi

nginx出现 input file not specfiried字样 请检查phpcgi的配置

nginx配置yii的美化url  
可以用!-f request_file来检测  也可以用try_files
try_files $url $url/ /index.php?$args;





