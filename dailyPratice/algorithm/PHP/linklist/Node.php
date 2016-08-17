<?php
//结点
class Node
{
    private $_id;
    private $_data;
    private $_next;
    
    public function __construct($id, $data, $next=null){
        $this->_id = $id;
        $this->_data = $data;
        $this->_next = $next;
    }
    
    public function __get($name){
        $name = "_".$name;
        if(property_exists($this, $name)){
            return $this->$name;
        }
    }
    
    public function __set($name, $value){
        $name = "_".$name;
        if(property_exists($this, $name)){
            $this->$name = $value;
        }
    }
    
    public function __tostring()
    {
        return "pos is ".$this->id."  ".$this->data."  and the next is ".$this->next. "    ";
    }
}