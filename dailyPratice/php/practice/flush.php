<?php


ob_start();



$str = 'this is my flush test!this is my flush test!this is my flush test!this is my flush test!';
$i=0;

while($i<strlen($str)){
	$amout = mt_rand(1,5);
	for($j=0;$j<$amout;$j++){
		if($i+$j >= strlen($str)){
			break;
		}
		echo $str[$i+$j];
		ob_flush();
		flush();
		usleep(100*1000);
	}
	$i = $i+$j;
	ob_flush();
	flush();
	$time = mt_rand(300,999);
	usleep($time*1000);
}

ob_end_flush();