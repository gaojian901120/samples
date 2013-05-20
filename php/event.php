<?php
//EventSubscriber �������Listener
interface EventSubscriber {
   public function getSubscribedEvents();
}
class CustomeEventSubscriber implements EventSubscriber {
	public function getSubscribedEvents() {
		return array(
			'respone'=>array(
				array('onResponse1',3),
				array('onResponse2',1),
				array('onResponse3',2)
			)
		);
	}
	public function onResponse1(Event $event) {
		 $event->onResponse(__FUNCTION__);
	}
	public function onResponse2(Event $event) {
		 $event->onResponse(__FUNCTION__);
	}
	public function onResponse3(Event $event) {
		 $event->onResponse(__FUNCTION__);
	}
}
//Event �¼�
class Event {
	private $popagationStopped = false;
	public function setPopagationStopped() {
		$this->popagationStopped = true;
	}
	public function isPopagationStopped() {
		return $this->popagationStopped;
	}
}
class CustomEvent extends Event {
	public function onResponse($function) {
		echo $function . ' Event executed!!!<br/>';
	}
}
//EventDispather  �¼��ַ�
class EventDispather {
	private $_listeners = array();
	private $_sorted_listeners = array();
	public function addListener($name,$listener,$priority=0) {
		$this->_listeners[$name][$priority][] = $listener;
	}
	public function dispather($name,Event $event = null) {
		if(null == $event) {
			$event = new Event();
		}
		if(!isset($this->_sorted_listeners[$name])) {
			$this->sortListeners($name);
		}
		foreach($this->_sorted_listeners[$name] as $listener) {
			if(is_callable($listener)) {
				call_user_func($listener,$event);
			}
		}
	}
	public function addSubscriber(EventSubscriber $subscriber) {
		foreach($subscriber->getSubscribedEvents() as $name=>$params) {
			if(is_string($params)) {
				$this->addListener($name,array($subscriber,$params));
			} else if (is_string($params[0])) {
				$this->addListener($name,array($subscriber,$params[0]),isset($params[1]) ? $params[1] : 0);
			} else {
				foreach($params as $listener) {
					$this->addListener($name,array($subscriber,$listener[0]),isset($listener[1]) ? $listener[1] : 0);
				}
			}
		}
	}
	private function sortListeners($name) {
		$this->_sorted_listeners[$name] = array();
		if(isset($this->_listeners[$name])) {
			krsort($this->_listeners[$name]);
			$this->_sorted_listeners[$name] = call_user_func_array('array_merge', $this->_listeners[$name]);
		}
	}
}
//ʵ�����¼�
$event = new CustomEvent();
//��֯ð���¼�
//$event->setPopagationStopped();
//ʵ�����¼��ṩ��
$event_subscriber = new CustomeEventSubscriber();
//ʵ�����¼��ַ���
$event_dispather = new EventDispather();
//����¼��ṩ��
$event_dispather->addSubscriber($event_subscriber);
//ִ���¼�
$event_dispather->dispather('respone', $event);

