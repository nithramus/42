<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
date_default_timezone_set('Europe/Paris');



Class Vertex {
	private $_x, $_y, $_z = 0;
	private $_w = 1.0;
	private $_color;
	public static $verbose = False;
	public function __construct (array $array) {
		if (array_key_exists('x', $array) && array_key_exists('z', $array)
			&& array_key_exists('y', $array))
		{
			$this->_x = $array['x'];
			$this->_y = $array['y'];
			$this->_z = $array['z'];
		}
		if (array_key_exists('w', $array))
			$this->_w = $array['w'];
		else
			$this->_w = 1.0;
		if (array_key_exists('color', $array))
			$this->_color = $array['color'];
		else
			$this->_color = new Color(array ('rgb' => 0xffffff));
		if (self::$verbose === True)
		{
			print ('Vertex( x: '. $this->_x.', y: '. $this->_y .', z: '. $this->_z .', w: '. $this->_w.', '.$this->_color.' constructed.'. PHP_EOL);
		}
	}
	public function __destruct() {
		if (self::$verbose === True)
			print ('Vertex( x: '. $this->_x.', y: '. $this->_y .', z: '. $this->_z .', w: '. $this->_w.', '.$this->_color.' destructed.'. PHP_EOL);
	}
	public static function doc() {
		return (file_get_contents("Vertex.doc.txt"));
	}
	public function __toString() {
		$str = 'Vertex( x: '. $this->_x.', y: '. $this->_y .', z: '. $this->_z .', w: '. $this->_w;
		if (self::$verbose)
			$str = $str . ' , ' .$this->_color . ')';
		else
			$str = $str . ')';
		return ($str);
	}

	public function get_x () { return $this->_x ;}
	public function get_y () { return ($this->_y) ;}
	public function get_z () { return ($this->_z) ;}
	public function get_color () { return ($this->_color) ;}
	public function get_w () { return ($this->_w) ;}

	public function set_x ($value) { $this->_x = $value;}
	public function set_y ($value) { $this->_y = $value;}
	public function set_z ($value) { $this->_z = $value;}
	public function set_w ($value) { $this->_w = $value;}
	public function set_color ($value) { $this->_color = $value;}

//	public function set_color (Color $color) { $this->_color = $color;}
}
?>
