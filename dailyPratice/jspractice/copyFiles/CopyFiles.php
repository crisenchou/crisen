<?php
/***
*  把源目录中的指定文件名，按照目录的结构拷贝新的目录下，可以用于版本控制
*  author : crisen@2016/1/11
***/
class CopyFiles{
	
	public $sourceDir;
	public $desDir;
	public $copiedFiles = array();
	public $fileArr = array();
	public $aleadyFiles = array();
	public function __construct($sourceDir, $desDir = "", $copiedFiles = "")
	{
		$this->sourceDir = str_replace("\\","/",$sourceDir);
		$this->desDir = str_replace("\\","/",$desDir);
		$this->copiedFiles = $copiedFiles;
	}
	
	//创建测试环境需要的目录
	public function createTestfiles($file, $str)
	{
		$dir =  $this->desDir.dirname($file);
		$filename = basename($file);
		if( !is_dir($dir) )
		{
			mkdir(iconv("UTF-8", "GBK", $dir),0777,true); 
		}
		chdir($dir);
		$f = fopen($filename,"w");
		fwrite($f,$str);
		fclose($f);
	}
	
	//更改目录格式
	public function getSourceRealDir($dir)
	{
		$str = str_replace($this->sourceDir,"",$dir);
		$str = str_replace("\\","/",$str);
		return $str;
	}
	
	//遍历源目录
	public function ergodicDir($dir)
	{

		$handle = opendir($dir);
		while(($file = readdir($handle)) !== false)
		{
			if($file == "." || $file == "..")
			{
				continue;
			}
			chdir($dir);
			if( is_dir($file) )
			{
				$this->ergodicDir($dir."/".$file);
			}
			else
			{
				if( empty($this->copiedFiles) )
				{
					$this->fileArr[] = $dir."/".$file;
					continue;
				}
				if($file == $this->copiedFiles || in_array($file,$this->copiedFiles))
				{
					$this->fileArr[] = $dir."/".$file;
				}
			}
		}
		closedir($handle);
	}
	
	public function run()
	{
		$this->ergodicDir($this->sourceDir);
		if(empty($this->fileArr))
		{
			throw new Exception("not match files");
		}
		foreach($this->fileArr as $key=>$val)
		{
			$str = file_get_contents($val);
			$filename = $this->getSourceRealDir($val);
			$this->aleadyFiles[] = $filename;
			$this->createTestfiles($filename,$str);
		}
	}
}
?>