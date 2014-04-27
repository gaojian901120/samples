<?php
require_once '../Thrift/ClassLoader/ThriftClassLoader.php';
require_once 'Demo.php';
require_once 'Types.php';

use Thrift\ClassLoader\ThriftClassLoader;
use Thrift\Transport\TSocket;
use Thrift\Transport\TBufferedTransport;
use Thrift\Protocol\TBinaryProtocolAccelerated;

use demo\DemoClient;

$loader = new ThriftClassLoader();
$loader->register();
$loader->registerNamespace('Thrift\Base', dirname(dirname(__FILE__)));
$loader->registerNamespace('Thrift\Type', dirname(dirname(__FILE__)));
$loader->registerNamespace('Thrift\Exception', dirname(dirname(__FILE__)));
$loader->registerNamespace('Thrift\Transport', dirname(dirname(__FILE__)));
$loader->registerNamespace('Thrift\Protocol', dirname(dirname(__FILE__)));
$loader->registerNamespace('Thrift\Factory', dirname(dirname(__FILE__)));
$loader->registerNamespace('Thrift\StringFunc', dirname(dirname(__FILE__)));
$loader->registerNamespace('demo', dirname(dirname(__FILE__)));

//TBase
$loader->loadClass('TBase');
//Type
$loader->loadClass('TType');
$loader->loadClass('TMessageType');
//Transport
$loader->loadClass('TSocket');
$loader->loadClass('TBufferedTransport');
//Protocol
$loader->loadClass('TProtocol');
$loader->loadClass('TBinaryProtocolAccelerated');
//Factorys
$loader->loadClass('TStringFuncFactory');
//StringFunc
$loader->loadClass('Core');
//Exception
$loader->loadClass('TException');
$loader->loadClass('TProtocolException');
$loader->loadClass('TApplicationException');

try {
	$host = '127.0.0.1';
	$port = 9090;
	$socket = new TSocket($host ,$port);  
	$transport = new TBufferedTransport($socket, 1024, 1024);  
	$protocol = new TBinaryProtocolAccelerated($transport); 

	$client = new DemoClient($protocol);
	$transport->open();

	$ret = $client->hello("Hello world!!");
	echo $ret;

	$transport->close();
} catch (TException $e) {
	print 'Something went wrong: ' . $e->getMessage() . "\n";  
}
