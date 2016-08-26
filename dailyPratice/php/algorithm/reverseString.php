<?php
/*
* reverse string
*/
function reverseString($str = "")
{
    $resStr = "";
    $len = strlen($str);
    if($len > 1){
        for($i=$len-1; $i>=0; $i--){
            $resStr .= $str{$i};
        }
        return $resStr;
    }else{
        return $str;
    }
}

//三步反转   hello world -> dlrow hello
function threeStepReverse($str){
    $strLeft = substr($str, 0, 5);
    $strRight = substr($str, 5);
    $strLeft = reverseString($strLeft);
    return reverseString($strLeft.$strRight);
}
$str = "hello world";
echo threeStepReverse($str);