<?php
//Algorithm quick sort
function q_sort($arr = [])
{
    $arraySize = count($arr);
    if($arraySize > 1){
        $k          = $arr[0];
        $arrLeft    = [];
        $arrRight   = [];
        for($i=1; $i<$arraySize; $i++){
            if($arr[$i] <= $k){
                $arrLeft[] = $arr[$i];
            }else if($arr[$i] > $k){
                $arrRight[] = $arr[$i];
            }
        }
        $arrLeft  = q_sort($arrLeft);
        $arrRight = q_sort($arrRight);
        return array_merge($arrLeft, [$k], $arrRight);
    }else{
        return $arr;
    }
}