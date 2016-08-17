<?php
/*
* 解析大文件的最后的1024字节
* crisenchou@20160714
* unix操作系统可以直接使用tail命令直接获取大文件的最后的内容
*/
class FileParse{
    public $handle;
    public $filename;
    public function __construct($filename, $mode = "r")
    {
        try{
            if(!file_exists($filename) === false){
                $this->handle = fopen($filename, $mode);
                $this->$filename = $filename;
            }else{
                throw new Exception("文件不存在");
            }
        }catch(Exception $e){
            echo $e->getMessage();
            exit;
        }
    }
    
    //解析文件
    public function parse($position = -1024)
    {
        fseek($this->handle, $position, SEEK_END);
        while(!feof($this->handle) && $line = fgets($this->handle)){
            echo $line;
        }
    }
}

$file = new FileParse("php.ini");
$file->parse();
?>