<?php


/***
 * author : crisen
 * ������ǰĿ¼,�����е�html��׺�ļ��޸ĳ�laravel bladeģ���ļ�
***/
$dir = ".";

// ��Ŀ¼��Ȼ���ȡ������
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