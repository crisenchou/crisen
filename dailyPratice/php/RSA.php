<?php

//需要开启php GMP扩展

class RSA{
    private $__E;
    private $__D;
    private $__N;
    private $__P;
    private $__Q;
    
    public function __construct()
    {
        // $this->__P = $this->getPrime();
        // $this->__Q = $this->getPrime();
        
        // $this->__P = 3;
        // $this->__Q = 5;
        
        // $this->__N = $this->__P*$this->__Q;
        // $this->__E = 3;
        // $d = $this->getD();
        // $this->__D = $d;
        
        $this->__P = 7;
        $this->__Q = 5;
        $this->__N = 143;
        $this->__E = 7;
        $this->__D = 103;
    }
    
    //chr() ASCII->char   ord()   char->ASCII

    //加密
    public  function encrypt($m)
    {
        return gmp_mod(gmp_pow($m, $this->__E),$this->__N);
    }
    
    //解密
    public function decrypt($c)
    {
        return gmp_mod(gmp_pow($c, $this->__D),$this->__N);
    }
    
    
    //在区域内获得一个随机素数
    public function getPrime($from=10, $to=50)
    {
        $randNum = mt_rand($from, $to);
        
        while(!$this->isPrime($randNum)){
            ++$randNum;
        }
        return $randNum;
    }
    
    
    //判断是否是素数
    public function isPrime($n)
    {
        for($i=2;$i*$i<=$n;$i++){
            if($n%$i==0){
                return false;
                break;
            }
        }
        return true;
    }

    //gmp_init
    //求n的欧拉数
    public function eular($n)
    {
        $ret=1;
        for($i=2;$i*$i<=$n;$i++)
        {
            if($n%$i==0)
            {
                $n/=$i;
                $ret*=$i-1;
                while($n%$i==0)
                {   $n/=$i;
                    $ret*=$i;
                }
            }
        }
        if($n>1) $ret*=$n-1;
        return $ret;
    }
    
    
    public function getD()
    {
        
        $k = ($this->__P-1)*($this->__Q-1);
        
        
        $this->__E = $this->getE($k);
        
        // echo $this->__E;exit;
        
        //$this->__E = $k-1;
        
        //$eulerNum = $this->eular($this->__N);
        
        for($d=1;$d<=$k;$d++){
            $pow =  $this->__E * $d;
            if($pow % $k == 1){
                echo $d;
                break;
            }
        }
        return $d;
    }
    
    
    public function isRelativePrime($min,$max){
        if($max % $min ==0){
            return false;
        }
        
        for($i=2;$i<$min;$i++){
            if($max%$i==0 && $min%$i==0){
                return false;
                break;
            }
        }
        
        return true;
    }
    
    public function getE($n){
        for($i=2;$i<$n;$i++){
            if($this->isRelativePrime($i,$n)){
                return $i;
                break;
            }
        }
        return false;
    }
    
    public function check(){
        for($i=1;$i<$this->__N;$i++){
            $encrypt = $this->encrypt($i);
            $message = $this->decrypt($encrypt);
            echo "the encrypt is ".$encrypt;
            echo PHP_EOL;
            echo "the message is ".$message;
            echo PHP_EOL;
        }
    }
    
    //chr() ASCII->char   ord()   char->ASCII
    public function enctyptMessage(){
        $message = "abc";
        $encrypt = [];
        for($i=0;$i<strlen($message);$i++){
            $num = ord($message{$i});
            //$ord = (int)$this->encrypt($num);
            $encrypt[$i] = $this->encrypt($num);
        }
        
        $str = "";
        foreach($encrypt as $val){
            $ord = (int)$this->decrypt($val);
            $str .= chr($ord);
        }
        
        echo $str;exit;
        var_dump($encrypt);exit;
        
        $this->checkstring($encrypt);
        
        var_dump($encrypt);
        exit;
        return $encrypt;
    }
    
    
    public function checkstring($str){
        for($i=0;$i<strlen($str);$i++){
           echo ord($str{$i});
        }
    }
    
    public function test(){
        $this->__P = $this->getPrime();
        $this->__Q = $this->getPrime();
        $this->__P = 11;
        $this->__Q = 13;
        $this->__N = ($this->__P)*($this->__Q);
        //$this->__E = 3;
        $d = $this->getD();
        $this->__D = $d;
    }
    
}


$rsa = new RSA();

$en = $rsa->enctyptMessage();
echo $en;exit;
$rsa->check();

// $rsa->test();var_dump($rsa);


exit;








