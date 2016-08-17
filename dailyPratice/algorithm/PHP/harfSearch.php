<?php
/*
* half search 折半查找
*/
function halfSearch($num, $arr=[])
{
    if(!empty($arr)){
        $mid = intval(count($arr)/2);
        if($num > $arr[$mid]){
            $arr = array_slice($arr, $mid);
            return halfSearch($num, $arr);
        }else if($num < $arr[$mid]){
            $arr = array_slice($arr, 0, $mid);
            return halfSearch($num, $arr);
        }else{
            return $mid;
        }
    }else{
        return $num;
    }
}