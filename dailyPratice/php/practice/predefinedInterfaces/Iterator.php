<?php
class myIterator implements Iterator{
    private $__position = 0;
    private $__array = [
        'first',
        'second',
        'third'
    ];


    public function __construct(){
        $this->__position = 0;
    }
    
    final public function rewind(){
        var_dump(__METHOD__);
        $this->__position = 0;
    }
    
    
    final public function current(){
        var_dump(__METHOD__);
        return $this->__array[$this->__position];
    }
    
    final public function key(){
        var_dump(__METHOD__);
        return $this->__position;
    }
    
    final public function next(){
        var_dump(__METHOD__);
        ++$this->__position;
    }
    
    final public function valid() {
        var_dump(__METHOD__);
        return isset($this->__array[$this->__position]);
    }
}

$it = new myIterator;
foreach($it as $key=>$value)
    var_dump($key,$value);

