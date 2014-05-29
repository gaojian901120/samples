<?php
abstract class engine
{
	public $_urls = array();
	abstract public function add_url($url);
	abstract public function exec();
}