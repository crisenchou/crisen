<?php
/*
* merge sort  �鲢����
*/
// �ϲ�����
function merge($arrLeft=[], $arrRight=[])
{
    $arrResult = [];
    while(count($arrLeft) && count($arrRight)){
        $arrResult[] = $arrLeft[0] < $arrRight[0] ? array_shift($arrLeft) : array_shift($arrRight);
    }
    return array_merge($arrResult, $arrLeft, $arrRight);
}

// �鲢����������
function mergeSort($arr)
{
    $arrSize = count($arr);
    if($arrSize > 1){
        $arrMid   = intval($arrSize/2);
        $arrLeft  = array_slice($arr, 0, $arrMid);
        $arrRight = array_slice($arr, $arrMid);
        $arrLeft  = mergeSort($arrLeft);
        $arrRight = mergeSort($arrRight);
        return merge($arrLeft, $arrRight);
    }else{
        return $arr;
    }
}