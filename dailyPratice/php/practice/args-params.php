<?php
/**
 *  by $argc $argv 
 */

echo "accept {$argc} args, and the argument is ";
print_r($argv);

/***
*** by STDOUT & STDIN  I/O
***/
fwrite(STDOUT,'write something');
var_dump(fgets(STDIN));

/***
*** by getopt
***/
$param_arr = getopt('a:b:');
print_r($param_arr);

/*
* test statement
*/
//php args.php -a 345 -b 1235



// by std example
/**
 * 提示用户输入，类似Python
 */
// $fs = true;
// do{
// if($fs){
// fwrite(STDOUT,'请输入您的博客名：');
// $fs = false;
// }else{
// fwrite(STDOUT,'抱歉，博客名不能为空，请重新输入您的博客名：');
// }
// $name = trim(fgets(STDIN));
// }while(!$name);
// echo '您输入的信息是：'.$name."\r\n";


