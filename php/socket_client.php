<?php
set_time_limit(0);
$host = "192.168.1.119";
$port = 80;

$header = "HEAD / HTTP/1.1\n";
$header .= "Host: 192.168.1.119\n";
$header .= "Connection: keep-alive\n";
$header .= "Accept: text/html,application/xhtml+xml,application/xml;\n";
$header .= "Accept-Charset: utf-8\n";
$header .= "Accept-Encoding: gzip, deflate\n";
$header .= "Cache-Control: max-age=3600\n";
$header .= "Expire: " . gmdate ("D, d M Y H:i:s", time() + 3600) . " GMT";
$header .= "User-Agent: PHP\n";

if (($handle = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false) {
    echo "socket_create() failed: " . socket_strerror(socket_last_error()) . "\n";
}
if(($result = socket_connect($handle, $host, $port)) === false) {
	echo "socket_connect() failed: " . socket_strerror(socket_last_error($handle)) . "\n";
}

socket_write($handle, $header, strlen($header));
while (($out = socket_read($handle, 10240)) !== FALSE) {
    echo $out;
}
socket_close($handle);
/*
$fp = fsockopen($host,$port,$errno,$errstr);
if(!$fp) {
	echo "Error: " . $errno . " - " . $errstr . "<br/>\n";
} else {
	fwrite($fp,$header);
	echo fread($fp,10240);
	fclose($fp);
}
*/
