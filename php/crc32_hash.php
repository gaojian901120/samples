<?php
$str = 'ada';
$hash = decbin(crc32($str));
print_r($hash . '<br/>');
$hash_table = array(
	1 => array(
	    0 => 'server_a',
		1 => 'server_b'
	),
	0 => array(
		0 => 'server_c',
		1 => 'server_d'
	)
);
$server = NULL;
while($hash_table) {
	if(isset($hash_table[$hash[0]])) {
		if(is_array($hash_table[$hash[0]])) {
			$hash_table = $hash_table[$hash[0]];
			$hash = substr($hash,1);
		} else {
			$server = $hash_table[$hash[0]];
			break;
		}
	} else {
		break;
	}
}
print_r($server);