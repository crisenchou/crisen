<?php
/*
* insert sort 直接插入排序
*/
function insertSort($arr)
{
    $arrSize = count($arr);
    if($arrSize > 1){
        for($i=1; $i<$arrSize; $i++){
            $tmp = $arr[$i];
            $key = $i-1;
            while($key>=0 && $tmp<$arr[$key]){
                $arr[$key+1] = $arr[$key];
                $key--;
            }
            if(($key+1) != $i){
                $arr[$key+1] = $tmp;
            }
        }
    }
    return $arr;
}