<?php
/*
*Reverse Polish notation  RPN  逆波兰表示法运算
*/
function reversePolishCount($arr)
{
    $stack = [];
    if(!empty($arr) === true){
        foreach($arr as $val){
            if(is_numeric($val)){
                array_push($stack, $val);
            }else if(isOperater($val) === true){
                switch($val){
                    case "+" : 
                        array_push($stack, array_pop($stack) + array_pop($stack));
                    break;
                    case "-" : 
                        $tempNum = array_pop($stack);
                        array_push($stack, array_pop($stack) - $tempNum);
                    break;
                    case "*" : 
                        array_push($stack, array_pop($stack) * array_pop($stack));
                        break;
                    case "/" : 
                        $tempNum = array_pop($stack);
                        if($tempNum == 0){
                            throw new Exception("0 is not availid");
                        }else{
                            array_push($stack, array_pop($stack) / $tempNum);
                        }
                    break;
                    default:
                        throw new Exception("not a illegle operater");
                    break;
                }
            }
        }
    }
    return $stack;
}

//判断是否是操作数 目前仅支持四则运算
function isOperater($char, $operaterLimit = ["+","-","*","/"])
{
    if(in_array($char, $operaterLimit)){
        return true;
    }
    return false;
}