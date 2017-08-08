<?php


function countAndSay($str){
    $newStr='';
    echo $str.PHP_EOL;
    sleep(1);
    ob_flush();
    flush();
    $i=0;
    $len = strlen($str);
    $count =1;
    
    
    while($i<$len){
        $say = $str[$i];
        if(isset($str[$i+1]) && $str[$i+1] == $say){
            $count ++;
        }else{
            $newStr .=  $count.''.$say;
            $count =1;
        }
        $i++;
    }
    return countAndSay($newStr);
}


ob_start();
countAndSay('1');

ob_end_flush();