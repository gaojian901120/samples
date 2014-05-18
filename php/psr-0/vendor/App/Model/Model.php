<?php
namespace vendor\App\Model;

use vendor\Base\Model\BaseModel;

class Model extends BaseModel {
	public function __construct() {
		parent::__construct();
		echo "init Model in " . __FILE__ . "\n";
	}
}