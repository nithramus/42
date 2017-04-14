<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
date_default_timezone_set('Europe/Paris');

Class Vector {
	private $_x, $_y, $_z = 0;
	private $_w = 0.0;
	public static $verbose = False;

	public function __construct (array $array) {
		if (array_key_exists('x', $array) && array_key_exists('z', $array)
			&& array_key_exists('y', $array))
		{
			$this->_x = $array['x'];
			$this->_y = $array['y'];
			$this->_z = $array['z'];
		}
		else if (array_key_exists('dest', $array))
		{
			if (array_key_exists('orig', $array))
				$temp = $array['orig'];
			else
				$temp = new Vertex(array('x' => 0, 'y'=> 0, 'z' => 0));
			$this->_x = $array['dest']->get_x() - $temp->get_x();
			$this->_y = $array['dest']->get_y() - $temp->get_y();
			$this->_z = $array['dest']->get_z() - $temp->get_z();
		}
		if (self::$verbose)
		{
			print ('Vector( x: '. $this->_x.', y: '. $this->_y .', z: '. $this->_z .', w: '. $this->_w.') constructed.'. PHP_EOL);
		}
	}

	public function __destruct() {
		if (self::$verbose)
			print ('Vector( x: '. $this->_x.', y: '. $this->_y .', z: '. $this->_z .', w: '. $this->_w.') destructed.'. PHP_EOL);
	}
	public function __toString() {
		return ('Vector( x: '. $this->_x.', y: '. $this->_y .', z: '. $this->_z .', w: '. $this->_w.')');
	}

	private function newvec($x, $y, $z)
	{
		return (new Vector(array('x' => $x, 'y' => $y, 'z' => $z)));
	}
	public static function doc() {
		return (file_get_contents("Vector.doc.txt"));
	}

	public function get_x () { return $this->_x ;}
	public function get_y () { return ($this->_y) ;}
	public function get_z () { return ($this->_z) ;}
	public function get_w () { return ($this->_w) ;}

	public function magnitude(){
		return (sqrt($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z));
	}
	public function normalize()
	{
		$max = $this->magnitude();
		if ($max == 0)
			return (new Vector(array('x' => 1, 'y' => 0, 'z' => 0)));
		return (new Vector(array('x' => $this->_x / $max, 'y' => $this->_y / $max,'z' => $this->_z / $max)));
	}
	public function add(Vector $vect)
	{
		return (new Vector(array('x' => $vect->get_x() + $this->_x,
			'y' => $vect->get_y() + $this->_y,
			'z' => $vect->get_z() + $this->_z)));
	}
	public function sub(Vector $vect)
	{
		return (new Vector(array('x' => $vect->get_x() - $this->_x,
			'y' => $vect->get_y() - $this->_y,
			'z' => $vect->get_z() - $this->_z)));
	}
	public function opposite() {
		return ($this->newvec(-$this->_x, -$this->_y, -$this->_z));
	}
	public function dotProduct(Vector $vec) {
		return ($this->_x * $vec->get_x() + $this->_y * $vec->get_y() + $this->_z * $vec->_z);
	}
	public function scalarProduct($k) {
		return ($this->newvec($this->_x * $k, $this->_y * $k, $this->_z * $k));
	}
	public function cos(Vector $vect){
		return ($this->dotProduct($vect) / ($this->magnitude() * $vect->magnitude()));
	}
	public function crossProduct(Vector $vect)
	{
		return ($this->newvec(($this->_y * $vect->get_z()) * ($this->_z * $vect->get_y()),
			($this->_z * $vect->get_x()) * ($this->_x * $vect->get_z()),
			($this->_x * $vect->get_y()) * ($this->_y * $vect->get_x())));
	}
}
