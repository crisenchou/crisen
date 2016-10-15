<?php
error_reporting(E_ALL);
set_time_limit(0);
echo "<h2>TCP/IP Connection</h2>\n";

$port = 23456;
$ip = "121.40.150.93";

/*
 +-------------------------------
 *    @socket
 +-------------------------------
 *    @socket_create
 *    @socket_connect
 *    @socket_write
 *    @socket_read
 *    @socket_close
 +--------------------------------
 */

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket < 0) {
    echo "socket_create() failed: reason: " . socket_strerror($socket) . "\n";
}else {
    echo "OK.\n";
}

echo "try to connect '$ip' at port '$port'...\n";
$result = socket_connect($socket, $ip, $port);
if ($result < 0) {
    echo "socket_connect() failed.\nReason: ($result) " . socket_strerror($result) . "\n";
}else {
    echo "connection OK\n";
}

$in = "Ho\r\n";
$in .= "first blood\r\n";
$out = '';

if(!socket_write($socket, $in, strlen($in))) {
    echo "socket_write() failed: reason: " . socket_strerror($socket) . "\n";
}else {
    echo "message send successful\n";
    echo "content:<font color='red'>$in</font> <br>";
}

while($out = socket_read($socket, 8192)) {
    echo "recieve message successful\n";
    echo "the back content:",$out;
}


echo "closing SOCKET...\n";
socket_close($socket);
echo "closed\n";
?>