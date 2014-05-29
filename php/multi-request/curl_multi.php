<?php
include "engine.php";
class curl_multi_engine extends engine
{
	public function __contruct($urls)
	{
		$this->_urls = $url;
	}

	public function add_url($url)
	{
		$this->_urls[] = $url;
	}

	public function exec() 
	{
		$conn = array();
		$running = null;
		$mh = curl_multi_init();
		foreach ($this->_urls as $i => $url) {
		    $conn[$i]=curl_init($url);
		    curl_setopt ($conn[$i], CURLOPT_RETURNTRANSFER, 1);
		    curl_multi_add_handle ($mh,$conn[$i]);
		}
		do {
            $mrc = curl_multi_exec($mh,$running);
        } while ($mrc == CURLM_CALL_MULTI_PERFORM);

		while ($running and $mrc == CURLM_OK) {
            if (curl_multi_select($mh) != -1) {
                do {
                    $mrc = curl_multi_exec($mh, $running);
                } while ($mrc == CURLM_CALL_MULTI_PERFORM);
            }
    	}
    	foreach ($this->_urls as $i => $url) {
			$res[$i]=curl_multi_getcontent($conn[$i]);
			curl_close($conn[$i]);
		}
	}
}