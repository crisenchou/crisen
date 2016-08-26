<?php
/*
* simple select sort 简单选择排序
*/
//find mininal value
function minValue($arr, $i=0){
    $arrSize = count($arr);
    if($arrSize <=1 ){
        return 0;
    }
    $key = $i;
    while($i < $arrSize){
        if($arr[$i] < $arr[$key]){
            $key = $i;
        }
        $i++;
    }
    return $key;
}

//select sort
function simpleSelectSort($arr)
{
    $arrSize = count($arr);
    if($arrSize > 1){
        for($i=1; $i<$arrSize; $i++){
            $key        = minValue($arr, $i);
            $temp       = $arr[$i];
            $arr[$i]    = $arr[$key];
            $arr[$key]  = $temp;
        }
    }
    return $arr;
}