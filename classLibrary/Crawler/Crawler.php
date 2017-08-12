<?php
/**
* �������
*
* crisenchou 2016-07-11
*/


function makeFullDir($dir){
    return  is_dir ( $dir ) or makeFullDir(dirname( $dir )) and  mkdir ( $dir , 0777);
}

class Crawler{
    public static $instance;
    public $targetUrl;
    public $baseUrl;
    public $css;
    public $js;
    public $html;
    public $images;
    public $url;
    public $source;
    
    private function __construct()
    {
        
    }

    
    //�ṩ�ⲿ����ʵ����Ψһ���
    public static function getinstance()
    {
        if(SELF::$instance instanceof Crawler){
            return SELF::$instance;
        }else{
            SELF::$instance = new Crawler();
            return SELF::$instance;
        }
    }
    
    //��ʼ����Ҫץȡ��url
    public static function init($targetUrl, $baseUrl='')
    {
        SELF::getinstance()->targetUrl = $targetUrl;
        if($baseUrl){
            SELF::getinstance()->baseUrl = $baseUrl;
        }else{
            SELF::getinstance()->baseUrl = $targetUrl;
        }
       
        
    }
    
    //��ȡҳ������
    public function getUrlContent()
    {
        $handle = fopen(SELF::getinstance()->targetUrl, "r");
        if($handle){
            $content = stream_get_contents($handle, 1024*1024);
            return $content;
        }else{
            return false;
        }
    }
    
    
    public function match($reg, $content){
        if(preg_match_all($reg, $content, $result)){
            return $result[1];
        }else{
            return null;
        }
    }
    
    //ץȡҳ�����е�url
    public function getUrls($webContent)
    {
        $reg = '/<[a|A].*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }

    //ץȡҳ��css
    public function getCsss($webContent)
    {
        $reg = '/<link.*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }
    
    //ץȡҳ��js
    public function getJss($webContent)
    {
        $reg = '/<script.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }
    
    //ץȡͼƬ
    public function getImages($webContent)
    {
        $reg = '/<img.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }
    
    
    //�������·��
    public function fixPath($url)
    {
        if(strpos($url, "https")!==false || strpos($url, "http") !==false){
            return $url;
        }
        if($url == "#" || strpos($url,'javascript:') !== false){
            $url = '';
        }
        return SELF::getinstance()->baseUrl.'/'.trim($url, "/");
    }
    
    //����·��
    public function parsePath(){
        //do something
    }
    
    //��������
    public static function run()
    {
        $instance = self::getinstance();
        $content = $instance->getUrlContent();
        $url = array_unique($instance->getUrls($content));
        $css = $instance->getCsss($content);
        $js = $instance->getJss($content);
        $images = $instance->getImages($content);
        $arr = array_unique(array_merge($url,$css,$js,$images));
        foreach($arr as &$val){
            $val = $instance->fixPath($val);
        }
        $instance->source = array_unique($arr);
        $instance->downloadSource();
    }
    
    
    //������Դ
    public function downloadSource(){
        $instance = self::getinstance();
        if(!empty($instance->source)){
            foreach($instance->source as $source){
                $content = @file_get_contents($source);
                $parse = parse_url($source);
                if(!isset($parse['path'])){
                    continue;
                }
                $filename = $parse['path'];
                $dir =  ltrim(dirname($filename),'/');
                if(!file_exists($dir)){
                    makeFullDir($dir);
                }
                if($filename == '/'){
                    continue;
                }
                $filename = ltrim($filename, '/');
                echo $filename.PHP_EOL;
                if(!file_put_contents($filename, $content)){
                    echo $filename.'write fail';
                }else{
                    echo $filename.'write success';
                }
                ob_flush();
                flush();
            }
        }
    }
}


ob_start();
$url = "https://vesteraalens.no/hjem";
Crawler::init($url, "https://vesteraalens.no");
Crawler::run();
echo "ok";
ob_end_flush();