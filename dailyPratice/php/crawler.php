<?php
/**
* �������
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
    public static function init($target_url)
    {
        SELF::getinstance()->target_url = $target_url;
    }
    
    //��ȡҳ������
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
    
    //ץȡҳ�����е�url
    public function getUrls($web_content)
    {
        $reg_tag_a = '/<[a|A].*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        $result = preg_match_all($reg_tag_a, $web_content, $match_result);
        if($result){
            return $match_result[1];
        }
    }
    
    //ץȡҳ��css
    public function getCsss($web_content)
    {
        $reg_tag_link = '/<link.*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        $result = preg_match_all($reg_tag_link, $web_content, $match_result);
        if($result){
            return $match_result[1];
        }
    }
    
    //ץȡҳ��js
    public function getJss($web_content)
    {
        $reg_tag_script = '/<script.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        $result = preg_match_all($reg_tag_script, $web_content, $match_result);
        if($result){
            return $match_result[1];
        }
    }
    
    //ץȡͼƬ
    public function getImages($web_content)
    {
        $reg_tag_img = '/<img.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        $result = preg_match_all($reg_tag_img, $web_content, $match_result);
        if($result){
            return $match_result[1];
        }
    }
    
    //�������·��
    public function fixPath($url)
    {
        if(strpos($url, "http")){
            return $url;
        }else{
            return SELF::getinstance()->target_url.'/'.trim($url, "/");
        }
    }
    
    //����·��
    public function parsePath(){
        //do something
    }
    
    //��������
    public static function run()
    {
        $content = self::getinstance()->getUrlContent();
        $url = array_unique(self::getinstance()->getUrls($content));
        $css = self::getinstance()->getCsss($content);
        $js = self::getinstance()->getJss($content);
        $images = self::getinstance()->getImages($content);
        $arr = array_unique(array_merge($url,$css,$js,$images));
        foreach($arr as &$val){
            $val = self::getinstance()->fixPath($val);
        }
        self::getinstance()->source = $arr;
        self::getinstance()->downloadSource();
    }
    
    //������Դ
    public function downloadSource(){
        if(!empty(self::getinstance()->source)){
            foreach(self::getinstance()->source as $source){
                $content = @file_get_contents($source);
                $filename = substr($source, strripos($source, '/'));
                if($filename == "/" || $filename == "#"){
                    $filename = "index";
                }else{
                    $filename = ltrim($filename, '/');
                }
                file_put_contents($filename, $content);
            }
        }
    }
}
// Crawler::init("http://www.crisen.org");
// Crawler::run();
$url = "http://www.crisen.org";
echo dirname($url)
?>