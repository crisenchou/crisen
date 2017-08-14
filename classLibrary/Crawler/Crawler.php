<?php
/**
 * �������
 *
 * crisenchou 2016-07-11
 */

function makeFullDir($dir)
{
    return is_dir($dir) or makeFullDir(dirname($dir)) and mkdir($dir, 0777);
}

class Crawler
{
    public static $instance;
    public $baseUrl;
    public $target = [];
    public $css = [];
    public $js = [];
    public $images = [];
    public $complete = [];
    public $url;
    public $source;

    private function __construct()
    {

    }


    //�ṩ�ⲿ����ʵ����Ψһ���
    public static function getinstance()
    {
        if (self::$instance instanceof Crawler) {
            return self::$instance;
        } else {
            self::$instance = new Crawler();
            return self::$instance;
        }
    }

    //��ʼ����Ҫץȡ��url
    public static function init($targetUrl, $baseUrl = '')
    {
        array_push(self::getinstance()->target, $targetUrl);
        if ($baseUrl) {
            self::getinstance()->baseUrl = $baseUrl;
        } else {
            self::getinstance()->baseUrl = $targetUrl;
        }
    }

    //��ȡҳ������
    public function getUrlContent($url)
    {
        $handle = @fopen($url, "r");
        if ($handle) {
            $content = stream_get_contents($handle, 1024 * 1024);
            return $content;
        } else {
            return false;
        }
    }


    public function match($reg, $content)
    {
        if (preg_match_all($reg, $content, $result)) {
            return $result[1];
        } else {
            return null;
        }
    }

    //ץȡҳ�����е�url
    public function getUrls($webContent)
    {
        $reg = '/<[a|A].*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg, $webContent);
    }

    //ץȡҳ��css
    public function getCsss($webContent)
    {
        $reg = '/<link.*?href=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg, $webContent);
    }

    //ץȡҳ��js
    public function getJss($webContent)
    {
        $reg = '/<script.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg, $webContent);
    }

    //ץȡͼƬ
    public function getImages($webContent)
    {
        $reg = '/<img.*?src=[\'\"]{0,1}([^>\'\"\ ]*).*?>/';
        return $this->match($reg, $webContent);
    }


    //�������·��
    public function fixPath($url)
    {
        if (strpos($url, "https") !== false || strpos($url, "http") !== false) {
            return $url;
        }
        return self::getinstance()->baseUrl . '/' . trim($url, "/");
    }

    //����·��
    public function parsePath()
    {
        //do something
    }


    public function isUrl($url)
    {
        if ($url == "#" || strpos($url, 'javascript:') !== false || strpos($url, 'http://') !== false) {
            return false;
        }

        if (!strpos($url, self::getinstance()->baseUrl)) {
            return false;
        }

        return true;
    }

    public function crawl($url)
    {
        $instance = self::getinstance();
        $content = $instance->getUrlContent($url);
        $instance->saveFile($url, $content);
        $urls = $instance->getUrls($content);
        if (count($urls)) {
            foreach ($urls as $url) {
                $url = $instance->fixPath($url);
                if ($instance->isUrl($url)) {
                    array_push($instance->target, $url);
                }
            }
        }

        $css = $instance->getCsss($content);
        if (is_array($css)) {
            $instance->css = array_unique(array_merge($instance->css, $css));
        }

        $js = $instance->getJss($content);
        if (is_array($js)) {
            $instance->js = array_unique(array_merge($instance->js, $js));
        }

        $images = $instance->getImages($content);
        if (is_array($images)) {
            $instance->images = array_unique(array_merge($instance->images, $images));
        }
    }

    //��������
    public static function run()
    {
        $instance = self::getinstance();
        while (!empty($instance->target)) {
            $url = array_shift($instance->target);
            if (!in_array($url, $instance->complete)) {
                array_push($instance->complete, $url);
                $instance->crawl($url);
            }
        }

        $sources = array_merge($instance->js, $instance->css, $instance->images);
        $instance->downloadSource($sources);
    }


    //������Դ
    public function downloadSource($sources)
    {
        $instance = self::getinstance();
        if (!empty($sources)) {
            foreach ($sources as $source) {
                $source = $instance->fixPath($source);
                $content = @file_get_contents($source);
                $instance->saveFile($source, $content);
            }
        }
    }


    public function saveFile($source, $content)
    {
        $parse = parse_url($source);
        if (!isset($parse['path'])) {
            return false;
        }
        $filename = $parse['path'];
        $dir = ltrim(dirname($filename), '/');
        if (!file_exists($dir)) {
            makeFullDir($dir);
        }
        if ($filename == '/') {
            return false;
        }
        $filename = ltrim($filename, '/');

        if(!$content){
            echo $filename . ' content is empty' . PHP_EOL;
            return false;
        }

        if (!file_put_contents($filename, $content)) {
            echo $filename . ' write fail' . PHP_EOL;
        } else {
            echo $filename . ' write success' . PHP_EOL;
        }
        ob_flush();
        flush();
    }
}


ob_start();
$url = "https://vesteraalens.no/hjem";
Crawler::init($url, "https://vesteraalens.no");
Crawler::run();
$instance = Crawler::getinstance();
echo "ok";
ob_end_flush();