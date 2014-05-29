<?php
include "curl_multi.php";

class benchmark
{
	private $_engine = array();
	private $_start_time = NULL;
	private $_end_time = NULL;
	public function __construct($engine, $urls = NULL)
	{
		if(is_array($engine)) {
			if($urls) {
				foreach($engine as $i=>$e) {
					$engine[$i]->_urls = $url;
				}
			}
			$this->_engine = $engine;
		} else if($engine instanceof engine) {
			if($urls) {
				$engine->_urls = $urls;
			}
			$this->_engine[] = $engine;
		} else {
			exit("engine type error");
		}
	}

	public function add_url($url)
	{
		foreach($this->_engine as $i=>$e) {
			$this->_engine[$i]->_urls[] = $url;
		}
	}

	public function exec()
	{
		$output = '';
		foreach($this->_engine as $i=>$e) {
			$this->_start_time = microtime(true);
			$e->exec();
			$this->_end_time = microtime(true);
			$output .= $this->output($i, $e);
		}
		echo $output;
	}

	private function output($name, $engine)
	{
		if($this->_start_time && $this->_end_time) {
			return $name . ': ' . count($engine->_urls) . ' requests totally spend ' . ($this->_end_time - $this->_start_time) . ' msec' . "\n";
		}
	}
}

$urls = array();
$engines['curl_multi'] = new curl_multi_engine();
$b = new benchmark($engines, $urls);
$b->exec();
