<?php


//��ţ�ٷ���ƽ����   ����
//$n Ϊ��Ҫ������� 1Ϊ��һ���Ե���
function NsqrIteration($y = 1, $n = 2)
{
    // abs()Ϊȡ����ֵ����
    while(abs(1/2*($y+$n/$y) - $y) >= 0.0000000000000001)
    {
        $y = 1/2*($y+$n/$y);
    }
    return $y;
}
echo NsqrIteration(); //2��ƽ����  Ϊ1.4142135623731
echo "<br />";
echo NsqrIteration(2,5);//5��ƽ����Ϊ 2.2360679774998
echo "<br />";
echo NsqrIteration(3,10);//10��ƽ���� 3.1622776601684
echo "<br />";

//��ţ�ٷ���ƽ����  �ݹ�
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
