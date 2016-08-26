<?php
/**
 * 使用 $argc $argv 接受参数
 */
 
if($argc >= 4){
	$opreateArr = ['+','-','*','/'];
	$arg1 = $argv[1];
    $arg2 = $argv[2];
	$operate = $argv[3];
	
	if(is_numeric($arg1) && is_numeric($arg2) && in_array($operate, $opreateArr)){
		$express = $arg1.$operate.$arg2;
		$sum = eval("return ".$arg1.$operate.$arg2.";");
		echo $express."=".$sum;
		exit;
	}
}
echo "invalid arguments";
