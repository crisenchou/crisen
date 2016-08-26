<?php
static $phpIniConfig = [];
$handle = fopen("php.ini","r");
if($handle){
    while(!feof($handle) && $line = fgets($handle)){
        if(strpos($line, ";") === false && strpos($line, "=") !== false){
            $tempArr = explode("=", $line);
            $phpIniConfig[$tempArr[0]] = $tempArr[1];
        }
    }
}
fclose($handle);
var_dump($phpIniConfig);
?>