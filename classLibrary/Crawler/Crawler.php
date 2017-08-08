<?php
/**
* 爬虫程序
*
* crisenchou 2016-07-11
*/

class Crawler{
    public static $instance;
    public $target_url;
    public $css;
    public $js;
    public $html;
    public $images;
    public $url;
    public $source;
    
    private function __construct()
    {
        
    }

    
    //提供外部访问实例的唯一入口
    public static function getinstance()
    {
        if(SELF::$instance instanceof Crawler){
            return SELF::$instance;
        }else{
            SELF::$instance = new Crawler();
            return SELF::$instance;
        }
    }
    
    //初始化需要抓取的url
    public static function init($target_url)
    {
        SELF::getinstance()->target_url = $target_url;
    }
    
    //获取页面内容
    public function getUrlContent()
    {
        $handle = fopen(SELF::getinstance()->target_url, "r");
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
    
    //抓取页面所有的url
    public function getUrls($webContent)
    {
        $reg = '/<[a|A].*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }

    //抓取页面css
    public function getCsss($webContent)
    {
        $reg = '/<link.*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }
    
    //抓取页面js
    public function getJss($webContent)
    {
        $reg = '/<script.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }
    
    //抓取图片
    public function getImages($webContent)
    {
        $reg = '/<img.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg,$webContent);
    }
    
    
    //修正相对路径
    public function fixPath($url)
    {
        if(strpos($url, "https") || strpos($url, "http")){
            return $url;
        }
        return SELF::getinstance()->target_url.'/'.trim($url, "/");
    }
    
    //解析路径
    public function parsePath(){
        //do something
    }
    
    //程序启动
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
        $instance->source = $arr;
        $instance->downloadSource();
    }
    
    //下载资源
    public function downloadSource(){
        $instance = self::getinstance();
        if(!empty($instance->source)){
            foreach($instance->source as $source){
                $content = @file_get_contents($source);
                
                $parse = parse_url($source);
                //parse_url
                //$filename = substr($source, strripos($source, '/'));
                $filename = $parse['path'];
                echo $filename.PHP_EOL;
                ob_flush();
                flush();
                if($filename == "/" || $filename == "#"){
                    $filename = "index";
                }else{
                    $filename = ltrim($filename, '/');
                }
                //file_put_contents($filename, $content);
            }
        }
    }
}
ob_start();
$url = "https://vesteraalens.no/hjem";
Crawler::init($url);
Crawler::run();
echo "ok";
ob_end_flush();