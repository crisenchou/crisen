<?php

//should use bigint class

class RSA{
    private $__E;
    private $__D;
    private $__N;
    
    public function __construct($e,$d,$n){
        $this->__E = $e;
        $this->__D = $d;
        $this->__N = $n;
    }
    
    //chr() ASCII->char   ord()   char->ASCII

    public  function encrypt($m){
        return pow($m, $this->__E)%$this->__N;
    }
    
    public function decrypt($c){
        return pow($c, $this->__D)%$this->__N;
    }
    
}


$rsa = new RSA(3,3,15);
$message = 7;
$encrypt = $rsa->encrypt($message);
$message = $rsa->decrypt($encrypt);
echo "the encrypt is ".$encrypt;
echo PHP_EOL;
echo "the message is ".$message;
