<?php


/***
 * author : crisen
 * ������ǰĿ¼,�����е�html��׺�ļ��޸ĳ�laravel bladeģ���ļ�
***/

function changeSuffix($dir = '.', $find = 'html', $replace = 'blade.php'){
    // ��Ŀ¼��Ȼ���ȡ������
    if (is_dir($dir)){
        if ($dh = opendir($dir)){
            while (($file = readdir($dh)) !== false){
                if($file != '.' && $file != '..'){
                    if(is_dir($file)){
                        changeSuffix($file);
                    }else{
                        $file = $dir.'/'.$file;
                        $filename = str_replace($find,$replace,$file);
                        rename($file,$filename);
                    }
                }
                // if(is_dir($file)){
                    // return changeSuffix($file)
                // }else{
                    // $filename = str_replace('html','blade.php',$file);
                // rename($file,$filename);
                // }
            }
        closedir($dh);
        }
    }
}

changeSuffix();

echo 'ok';


