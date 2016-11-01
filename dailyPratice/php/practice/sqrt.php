<?php


//用牛顿法求平方根   迭代
//$n 为需要求根的数 1为第一次试的商
function NsqrIteration($y = 1, $n = 2)
{
    // abs()为取绝对值函数
    while(abs(1/2*($y+$n/$y) - $y) >= 0.0000000000000001)
    {
        $y = 1/2*($y+$n/$y);
    }
    return $y;
}
echo NsqrIteration(); //2的平方根  为1.4142135623731
echo "<br />";
echo NsqrIteration(2,5);//5的平方根为 2.2360679774998
echo "<br />";
echo NsqrIteration(3,10);//10的平方根 3.1622776601684
echo "<br />";

//用牛顿法求平方根  递归
function NsqrReverse($y = 1, $n = 2)
{
    if(abs(1/2*($y+$n/$y) - $y) <= 0.0000000000000001)
    {
        return 1/2*($y+$n/$y);
    }
    else
    {
       return NsqrReverse(1/2*($y+$n/$y),$n);
    }
}
echo NsqrReverse();
echo "<br />";
echo NsqrReverse(2,5);
echo "<br />";
echo NsqrReverse(3,10);
