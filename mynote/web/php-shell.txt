php除了可以用$_GET和$_POST的方式来获取http请求的参数之外，还可以作为shell脚本来执行，其实PHP本来就是一门脚本语言，在命令行下执行php脚本获取传递的参数有三种方式
一 使用$argc, $argv变量
示例代码
echo "接收到{$argc}个参数";
print_r($argv);
二 使用getopt函数来获取
示例代码
$param_arr = getopt('a:b:');
print_r($param_arr);
三 提示用户输入
示例代码
fwrite(STDOUT,'请输入您的名字：');
echo '您的名字是：'.fgets(STDIN);