<?php
require_once("Node.php");

class LinkList
{
    public $header;
    
    //init linklist
    public function __construct(Node $node)
    {
        $this->header = $node;
    }
    
    //add node
    public function insertNode(Node $node)
    {
        if($this->header == null){
            $this->header = $node;
            return true;
        }
        
        $current = $this->header;
        if($current->id > $node->id){
            $node->next = $current;
            $this->header = $node;
            return true;
        }
        
        while($current->next != null){
            if ($current->next->id > $node->id) {
                $node->next = $current->next;
                $current->next = $node;
                return true;
            }
            $current = $current->next; 
        }
    }
    
    //delete node
    public function deleteNode($id)
    {
        $current = $this->header;
        while($current->next != null){
            if ($current->next->id == $id) {
                $current->next = $current->next->next;
                return true;
            }
            $current = $current->next; 
        }
        return false;
    }
    
    //update node data
    public function updateNode($id, $value)
    {
        $current = $this->searchNode($id);
        if($current != null){
            $current->data = $value;
            return true;
        }
        return false;
    }
    
    //search node
    public function searchNode($id)
    {
        $current = $this->header;
        if($current->id == $id){
            return $current;
        }
        while($current->next != null){
            if ($current->next->id == $id) {
                return $current->next;
            }
            $current = $current->next; 
        }
        return null;
    }
}