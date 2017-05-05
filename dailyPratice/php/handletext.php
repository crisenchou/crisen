<?php

$param_arr = getopt('f:');

if(isset($param_arr['f'])){
	$file = $param_arr['f'];
	if(file_exists($file)){
		$f = fopen($file,'r+');
		while(!feof($f)){
			$str = fgets($f);
			$str = preg_replace('/"(\S+)"/', '"{{asset(\'$1\')}}"', $str);
			echo $str;
			//fwrite($f,$str);
		}
		fclose($f);
		echo 'ok';
	}else{
		echo 'file not exist';
	}
}else{
	echo 'incilid params';
}
