<?php


function feiboRecursive($n){
    if($n==1 || $n==2){
        return 1;
    }else{
        return feiboRecursive($n-1)+feiboRecursive($n-2);
    }
    
}


//迭代
function feiboIteration($n){
    if($n<0){
        return 0;
    }
    if($n==1 || $n==2){
        return 1;
    }
    $feibo1=1;
    $feibo2=1;
    for($i=3;$i<=$n;$i++){
        $feibo = $feibo1+$feibo2;
        $feibo1 = $feibo2;
        $feibo2 = $feibo;
    }
    return $feibo;
    
}


//尾递归
function feiboTailRecursive($n, $feibo1=1, $feibo2=1){
    if($n==1){
        return $feibo1;
    }else if($n==2){
        return $feibo2;
    }else{
        $feibo;
        $feibo = $feibo1+$feibo2;
        $feibo1 = $feibo2;
        $feibo2 = $feibo;
        --$n;
        return feiboTailRecursive($n, $feibo1, $feibo2);
    }
}


//公式法
function feibo($n){
    return (pow((sqrt(5)+1)/2,$n)-pow((1-sqrt(5))/2,$n))/sqrt(5);
}


$param_arr = getopt('n:');

if(!isset($param_arr['n'])){
    echo "please use stament like 'php feibo.php -n 10'";
    exit;
}
   
$n = $param_arr['n'];

for($i=1;$i<=$n;$i++){
    printf("the %dth element of feibo is %d  -----Iteration\n",$i,feiboIteration($i));
}


for($i=1;$i<=$n;$i++){
    printf("the %dth element of feibo is %d  -----Recursive\n",$i,feiboRecursive($i));
}

for($i=1;$i<=$n;$i++){
    printf("the %dth element of feibo is %d  -----TailRecursive\n",$i,feiboTailRecursive($i,1,1));
}


for($i=1;$i<=$n;$i++){
    printf("the %dth element of feibo is %d  -----math\n",$i,feibo($i));
}