<?php


/***
 * author : crisen
 * 遍历当前目录,把所有的html后缀文件修改成laravel blade模版文件
***/

function changeSuffix($dir = '.', $find = 'html', $replace = 'blade.php'){
    // 打开目录，然后读取其内容
    if (is_dir($dir)){
        if ($dh = opendir($dir)){
            while (($file = readdir($dh)) !== false){
                if($file != '.' && $file != '..'){
                    if(is_dir($file)){
                        changeSuffix($file, $find, $replace);
                    }else{
                        $file = $dir.'/'.$file;
						if(!$find){
							$filename =  $file.$replace;
						}else{
							$filename = str_replace($find,$replace,$file);
						}
                        rename($file,$filename);
                    }
                }
            }
        closedir($dh);
        }
    }
}

changeSuffix('.','txt','md');

echo 'ok';