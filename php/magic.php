<?php
class magic {
	public function __construct() {
		echo '__construct';
	}
	public function __invoke() {
		echo '__invoke';
	}
	public function __destruct() {
		echo '__destruct';
	}
}
$magic = new magic();
$magic();