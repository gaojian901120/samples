<?php
namespace vendor\Base\Controller;

use vendor\Base\Controller\BaseController;

abstract class Controller extends BaseController {
	public function __construct() {
		parent::__construct();
		echo "init Controller in " . __FILE__ . "\n";
	}
}