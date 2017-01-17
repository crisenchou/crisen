<?php
$str = 'print "Hello, World!";';
$f = fopen('p.py','w');
fwrite($f,$str);
fclose($f);
system('python p.py');
unlink('p.py');