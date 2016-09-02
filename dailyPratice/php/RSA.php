<?php

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

    private function encode($m){
        return pow($m,$this->__E)%$this->__N;
    }
    
    private function decode($c){
        return pow($c,$this->__D)%$this->__N;
    }
    
    public function encrypt($message){
        for($i=0;$i<strlen($message);$i++){
            $encrypt .= chr($this->encode(ord($message{$i})));
        }
        return $encrypt;
    }
    
    public function decrypt($encrypt){
        $message = "";
        for($i=0;$i<strlen($encrypt);$i++){
            $message .= chr($this->encode(ord($encrypt{$i})));
        }
        return $message;
    }
}


//p=7 q=11
$rsa = new RSA(7,5,24);
$message = "abc";
$encrypt = $rsa->encrypt($message);
echo "the encrypt is ".$encrypt;
$message = $rsa->decrypt($encrypt);
echo "the message is ".$message;
