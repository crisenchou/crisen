<?php
/*
* �������ļ�������1024�ֽ�
* crisenchou@20160714
* unix����ϵͳ����ֱ��ʹ��tail����ֱ�ӻ�ȡ���ļ�����������
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
                throw new Exception("�ļ�������");
            }
        }catch(Exception $e){
            echo $e->getMessage();
            exit;
        }
    }
    
    //�����ļ�
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