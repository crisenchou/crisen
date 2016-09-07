<?php
/**
* @feibo  Interator
* feibonacci  f(x) = (((1+Г5)/2)^x - ((1-Г5)/2)^x)/Г5
*/
class FibonacciSequence implements Iterator
{
    protected $limit= 0;
        
    protected $key= 0;    
        
    public function __construct($limit = 20)
    {
        $this->limit = (integer)$limit;
    }
    
    public function current()
    {
        return round(
            (pow(((1 + sqrt(5)) / 2), $this->key) - pow((-1 / (1 + sqrt(5)) / 2), $this->key)) / sqrt(5),
            null
        );
    }

    public function key()
    {
        return $this->key;
    }

    public function next()
    {
        $this->key++;
    }

    public function rewind()
    {
        $this->key = 0;
    }

    public function valid()
    {
        return $this->key < $this->limit;
    } 
}


$feibo = new FibonacciSequence(20);
foreach($feibo as $number)
    printf('%d'.PHP_EOL,$number);

?>
