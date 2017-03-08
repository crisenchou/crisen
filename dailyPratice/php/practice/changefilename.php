<?php


/***
 * author : crisen
 * 遍历当前目录,把所有的html后缀文件修改成laravel blade模版文件
***/
$dir = ".";

// 打开目录，然后读取其内容
if (is_dir($dir)){
  if ($dh = opendir($dir)){
    while (($file = readdir($dh)) !== false){
        if(is_file($file)){
            $filename = str_replace('html','balde.php',$file);
            rename($file,$filename);
        }
    }
    closedir($dh);
  }
}