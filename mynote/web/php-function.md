PHP于1994年由Rasmus Lerdorf创建，刚刚开始是Rasmus Lerdorf为了要维护个人网页而制作的一个简单的用Perl语言编写的程序

extract(array) 将数组中的键名解析成变量
$arr = array("a"=>a,"b"=>c);
axtract($arr);
echo $a,$b;
得出ac;

ignore_user_abort允许用户在关闭浏览器之后，继续执行任务，从而达到异步处理的效果
parse_url可以解析url变成一个数组
isnumeric()检测变量是否是数字或者数字字符串

ini_set为一个配置选项设置值，可以设置时间区

get_class()返回对象的类的名字

ord() 获取字符的ASSIC地址
chr()输出ASSIC地址对应的字符

gettype() 获取变量的数据类型  相当于javascript的typeof

bin-> (Binary)二进制  dec-> (decimal)十进制  oct->(octal)八进制  hex-> (hexadecimal)十六进制
decbin() 把十进制的数转换成二进制
decoct() 十进制转换成八进制
dechex() 十进制转换成十六进制
octdex  八进制->十进制
hexdec 十六进制->十进制
bindec 二进制->十进制
bin2hex 二进制->十六进制
base_convert(number,from,to)任意进制转换

new static($val);  new self($val);  new self 返回当前类  new static    php5.3 延迟绑定  返回子类的状态

在去除数组中的重复元素时可以使用array_flip函数然后使用arrat_keys函数 再使用array_flip函数来进行
也可以使用array_unique来进行 但是使用后者用时会比较慢  因为array_unique在底层的实现使用的是快速排序算法  快排的时间是nlog(n)阶 所以在去重的时候  优先选择前者


交换两个数组的值
list($b, $a) = array($a, $b);
$a = array($b, $b = $a)[0];

路由系统是所有 PHP 框架的核心，路由承载的是 URL 到代码片段的映射，不同的框架所附带的路由系统是这个框架本质最真实的写照，一丝不挂，一览无余。

number_format函数 可以把数字格式化为千位分隔符数字

array_reduce 向用户自定义的一个函数发送一个值，并返回一个字符串


