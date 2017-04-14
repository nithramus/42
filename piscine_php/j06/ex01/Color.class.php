<?php
     error_reporting(E_ALL);
     ini_set('display_errors', 1);    

Class Color {
	public $red, $green, $blue = 0;
	public static $verbose = False;
	private $calc;

	public function __construct( array $argv ) {
		if ( array_key_exists('rgb', $argv))
		{
			$calc = intval($argv['rgb']);
			$this->blue = $calc % 256;
			$calc = $calc / 256;
			$this->green = $calc % 256;
			$calc = $calc / 256;
			$this->red = $calc % 256;
		}
		else if ( array_key_exists('red', $argv) &&
			array_key_exists('green', $argv) &&  array_key_exists('blue', $argv) )
		{
			$this->red =  intval($argv['red']);
			$this->green = intval($argv['green']);
			$this->blue = intval($argv['blue']);
		}
		if (self::$verbose === True)
		{
			print('Color( red: '. $this->red .', green: '. $this->green .', blue: '. $this->blue .') constructed.'. PHP_EOL);
		}
	}
	public function __toString() {
		return ('Color( red: '. $this->red .', green: '. $this->green .', blue: '. $this->blue .')' . PHP_EOL);
	}

	public function __destruct() {
			print('Color( red: '. $this->red .', green: '. $this->green .', blue: '. $this->blue .') destructed.'. PHP_EOL);
	}

	public static function doc() {
		return (include("Color.doc.txt"));
	}

	public function add (color $color)
	{
		$newcolor = new Color(array ('red' => $this->red + $color->red,
			'blue' => $this->blue + $color->blue,
			'green' => $this->green + $color->green));
		return $newcolor;
	}
	public function sub (color $color)
	{
		$newcolor = new Color(array ('red' => $this->red - $color->red,
			'blue' => $this->blue - $color->blue,
			'green' => $this->green - $color->green));
		return $newcolor;
	}
	public function mult ($color)
	{
		$newcolor = new Color(array ('red' => $this->red * $color,
			'blue' => $this->blue * $color,
			'green' => $this->green * $color));
		return $newcolor;
	}
}
