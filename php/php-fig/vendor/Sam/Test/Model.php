<?php
namespace vendor\Sam\Test;

class Model {
	public function __construct() {
		echo 'init Model<br/>';
	}
	public function call() {
		echo 'Model foo';
	}
}