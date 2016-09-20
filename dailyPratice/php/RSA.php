<?php

//需要开启php GMP扩展

class RSA{
    private $__E;
    private $__D;
    private $__N;
    private $__P;
    private $__Q;
    
    public function __construct($e)
    {
        // $this->__P = $this->getPrime();
        // $this->__Q = $this->getPrime();
        // $this->__N = gmp_mul($this->__P,$this->__Q);
        // $this->__E = $e;
        // $THIS->__d = $this->getD();
        
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
    public function getPrime($from=111111, $to=999999)
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

    //判断两个数属否互质
    private function isRelativePrime($min, $max)
    {

        if(gmp_mod($max,$min) ==0){
            return false;
        }
        
        for($i=2;$i<=$min;$i++){
            if( gmp_mod($max,$i) == 0 && gmp_mod($min,$i) == 0){
                return false;
            }
        }
        return true;
    }
    
    //求n的欧拉数
    public function getEulerNum($n){
        $sum=1;
        for($i=1;$i<$n;$i++){
            if($this->isRelativePrime($i,$n) === true){
                $sum += 1;;
            }
        }
        return $sum;
    }
    
    public function getD(){
        $flag = true;
        
        $num = gmp_mul($this->__P-1,$this->__Q-1);
        
        
        $eulerNum = $this->getEulerNum($num);
        
        var_dump($eulerNum);exit;
        
        while(true){
            $d = 100;
            
            if( gmp_mod(gmp_pow($this->__E,$d) % $eulerNum) ==1 ){
                break;
            }
            $d++;
        }
        return $D;
        
    }
    
}


function isPrime($n)
{
    for($i=2;$i*$i<=$n;$i++){
        if($n%$i==0){
            printf("%u\n", $i);
            return false;
            break;
        }
    }
    return true;
}

//echo ~18446744072499298262;
//echo PHP_EOL;

//var_dump(isPrime(1625256759));



exit;

// $rsa = new RSA(3);

// var_dump($rsa->isPrime(1210253353));exit;


// var_dump($rsa);exit;//加密数据不能大于N的值
// $message = 14;
// $encrypt = $rsa->encrypt($message);
// $message = $rsa->decrypt($encrypt);
// echo "the encrypt is ".$encrypt;
// echo PHP_EOL;
// echo "the message is ".$message;
