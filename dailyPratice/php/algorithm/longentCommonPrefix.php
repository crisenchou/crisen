<?php

function longestCommonPrefix($strings){
    $prefix = '';
    for($i=0;$i<strlen($strings[0]);$i++){
        if(alphaInSting($strings,$strings[0][$i],$i)){
            $prefix .= $strings[0][$i];
        }
    }
    return $prefix;
}

function alphaInSting($string,$alpha,$position){
    if(!count($string)){
        return false;
    }
    $res = true;
    for($i=0;$i<count($string);$i++){
        if(!isset($string[$i][$position])){
            return false;
        }
        if($alpha != $string[$i][$position]){
            $res = false;
        }
    }
    return $res;
}

$strings = ['abcd','abbbb','abedf','abfff'];

$prefix = longestCommonPrefix($strings);

var_dump($prefix);