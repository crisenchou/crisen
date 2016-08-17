<?php
/*
* 大整数操作类
* 
*/
class LargeIntOpration
{
    //加
    public static function plus($data = [], $data1 = [])
    {
        self::swap($data, $data1);
        $carry = 0;//进位
        $time = count($data);//循环次数
        for($i = 0; $i<$time; $i++)
        {
            if(!isset($data1[$i]))
            {
                $data1[$i] = 0;//用0补充数字长度
            }
            if($data[$i] + $data1[$i] + $carry < 10){
                $data[$i] = $data[$i] + $data1[$i] + $carry;
                $carry = 0;
            }else{
                $data[$i] = ($data[$i] + $data1[$i] + $carry) % 10;
                $carry = 1;
            }
        }
        return $data;
    }
    
    //减
    public static function minus($data = [], $data1 = [])
    {
        $sign = self::swap($data, $data1);//交换了数据表示负数
        $carry = 0;//进位
        for($i = 0; $i<count($data); $i++)
        {
            if(!isset($data1[$i]))
            {
                $data1[$i] = 0;//若数据长度不足 则用0补充
            }
            if($data[$i] + $carry >= $data1[$i])
            {
                $data[$i] = $data[$i] - $data1[$i] + $carry;
                $carry = 0;
            }
            else
            {
                $data[$i] = $data[$i] + 10 - $data1[$i] + $carry;
                $carry = -1;
            }
        }
        
        // 舍去首位的0
        for($k=count($data) -1; $k>=0; $k--)
        {
            if($data[$k] == 0){
                unset($data[$k]);
            }else{
                break;
            }
        }
        
        if($sign && !empty($data))
        {
            array_push($data, '-');
        }
        return $data;
    }
    
    //乘
    public static function multiplied($data = [], $data1 = [])
    {
        $result = [];
        $carry  = 0;
        self::swap($data, $data1);
        for($i = 0; $i<count($data); $i++)
        {
            for($j = 0; $j<count($data1); $j++)
            {
                $temp = $data[$i] * $data1[$j] + $carry;
                if(isset($result[$i+$j]))
                {
                    $temp  = $temp + $result[$i+$j];
                }
                
                if($temp / 10 > 0)
                {
                    if($i+1 == count($data) && $j+1 == count($data1))
                    {
                        $result[$i+$j] = $temp % 10;
                        $carry = (int)($temp / 10);
                        if($carry > 0){
                            array_push($result,$carry);
                        }
                    }
                    else
                    {
                        $result[$i+$j] = $temp % 10;
                        $carry         = (int)($temp / 10);
                    }
                }
                else
                {
                    $result[$i+$j] = $temp;
                    $carry = 0;
                }
            }
        }
        return $result;
    }
    
    //除  辗转相减
    public static function divided($data = [], $data1 = [])
    {
        if(self::isEmpty($data1))
        {
            return "0 不能作为除数";
        }
        $mer = 0;//商
        while(self::isLarge($data, $data1))
        {
            $data = self::minus($data,$data1);
            $mer++ ;
        }
        return [$mer];
    }
    
    //模  
    public static function mod($data = [], $data1 = [])
    {
        if(self::isEmpty($data1))
        {
            return "0 不能作为除数";
        }
        $flag = self::isLarge($data, $data1);
        if(!$flag)
        {
            return $data1;
        }
        while($flag)
        {
            $data = self::minus($data,$data1);
            $flag = self::isLarge($data, $data1);
        }
        if(!empty($data))
        {
            return $data;
        }
        return [];
    }
    

    //检测整数是否为0
    public static function isEmpty($data = [])
    {
        
        if(empty($data))
        {
            return true;
        }
        
        if($data[0] == 0 && count($data) == 1)
        {
            return true;
        }
        return false;
    }
    
    
    //交换
    public static function swap(&$data, &$data1)
    {
        $temp = [];
        if(self::isLarge($data, $data1))
        {
            return false;
        }
        $temp = $data;
        $data = $data1;
        $data1 = $temp;
        return true;
    }
    
    //判断大小
    public static function isLarge($data, $data1)
    {
        if(count($data) > count($data1))
        {
            return true;
        }
        if(count($data) == count($data1))
        {
            if($data[count($data) - 1] >= $data1[count($data1) - 1])
            {
                return true;
            }
        }
        return false;
    }
    
    //输出大整数  倒序
    public static function dump($data = [])
    {
        if(!self::isEmpty($data))
        {
            for($i = count($data)-1; $i>=0; $i--)
            {
                echo $data[$i];
            }
        }
        else
        {
            echo "0";
        }
    }
}