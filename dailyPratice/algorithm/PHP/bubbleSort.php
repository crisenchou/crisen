<?php
/*
* bubble sort  冒泡排序
*/
function bubbleSort($arr)
{
    $arrSize = count($arr);
    if($arrSize > 1){
        for($i=0; $i<$arrSize; $i++){
            for($j=$i+1; $j<$arrSize; $j++){
                if($arr[$i] > $arr[$j]){
                    $temp    = $arr[$i];
                    $arr[$i] = $arr[$j];
                    $arr[$j] = $temp;
                }
            }
        }
        return $arr;
    }else{
        return $arr;
    }
}