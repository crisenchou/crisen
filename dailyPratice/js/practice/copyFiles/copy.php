<?php
require_once "CopyFiles.php";
header("Content-Type:text/html; charset=utf-8");
if( !empty($_POST["sourcedir"])  && !empty($_POST["desdir"]) )
{
	$sourceDir = str_replace("\\","/",$_POST["sourcedir"]); // 指定源目录
	$desDir = str_replace("\\","/",$_POST["desdir"]);// 指定指定目标目录
	if( !empty($_POST["filename"]) )
	{
		if(strpos($_POST["filename"],","))
		{
			$filename = explode(",",$_POST["filename"]);
		}
		else if(strpos($_POST["filename"],"\r\n"))
		{
			$filename = explode("\r\n",$_POST["filename"]);
		}
		else
		{
			$filename = $_POST["filename"];
		}
	}
	else
	{
		$filename = "";
	}
	$obj = new CopyFiles($sourceDir,$desDir,$filename);
	$obj->run();
	if(count($obj->aleadyFiles) > 0)
	{
		foreach($obj->aleadyFiles as $key=>$val)
		{
			//echo "成功从目录".$sourceDir.$val."拷贝文件到".$desDir.$val;
			echo $val;
			echo "<br />";
		}
		echo "总计成功拷贝文件".count($obj->aleadyFiles)."个";
		echo "<br />";
	}
	else
	{
		echo "拷贝文件失败";
	}
}
else
{
	echo "指定的目录异常";
}