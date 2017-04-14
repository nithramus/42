<?PHP
include ("Vector.class.php");
Class Matrix {
	private $_final_matrice = array(array(1,0,0,0),array(0,1,0,0),array(0,0,1,0),array(0,0,0,1));
	private $_preset, $_scale, $_angle, $_vtc, $_fov, $_ratio, $_near, $_far = NULL;
	public static $verbose = False;
	const IDENTITY = 0;
	const SCALE = 1;
	const RX = 2;
	const RY = 3;
	const RZ = 4;
	const TRANSLATION = 5;
	const PROJECTION = 6;
	public function __construct(array $argv)
	{
		if (array_key_exists('preset', $argv))
			$this->_preset = $argv['preset'];
		if (array_key_exists('scale', $argv))
			$this->_scale = $argv['scale'];
		if (array_key_exists('angle', $argv))
			$this->_angle = $argv['angle'];
		if (array_key_exists('vtc', $argv))
			$this->_vtc = $argv['vtc'];
		if (array_key_exists('fov', $argv))
			$this->_fov = $argv['fov'];
		if (array_key_exists('ratio', $argv))
			$this->_ratio = $argv['ratio'];
		if (array_key_exists('near', $argv))
			$this->_near = $argv['near'];
		if (array_key_exists('far', $argv))
			$this->_far = $argv['far'];
		if ($this->_preset == self::TRANSLATION)
			$this->translation();
		else if ($this->_preset == self::RX)
			$this->Rot(1, 0, 0);
		else if ($this->_preset == self::RY)
			$this->Rot(0, 1, 0);
		else if ($this->_preset == self::RZ)
			$this->Rot(0, 0, 1);
		else if ($this->_preset == self::SCALE)
			$this->scale();
		print_r($this->_final_matrice);
	}
	private function translation(){
		$this->_final_matrice[0][0] += $this->_vtc->get_x();
		$this->_final_matrice[1][1] += $this->_vtc->get_y();
		$this->_final_matrice[2][2] += $this->_vtc->get_z();
		$this->_final_matrice[3][3] += $this->_vtc->get_w();
	}

	private function scale() {
		$i = 0;
		while ($i < 2)
		{
			$this->_final_matrice *= $this->_scale;
			$i++;
		}
	}

	private function Rot($x, $y, $z) {
		$this->_final_matrice[0][0] = $x * $x * (1 - cos($this->_angle)) + cos($this->_angle);
		$this->_final_matrice[0][1] = $x * $y * (1 - cos($this->_angle)) - $z * sin($this->_angle);
		$this->_final_matrice[0][2] = $x * $z * (1 - cos($this->_angle)) + $y * sin($this->_angle);
		$this->_final_matrice[1][0] = $y * $x * (1 - cos($this->_angle)) + $z *sin($this->_angle);
		$this->_final_matrice[1][1] = $y * $y * (1 - cos($this->_angle)) + cos($this->_angle);
		$this->_final_matrice[1][2] = $y * $z * (1 - cos($this->_angle)) - $x * sin($this->_angle);
		$this->_final_matrice[2][0] = $z * $x * (1 - cos($this->_angle)) - $y * sin($this->_angle);
		$this->_final_matrice[2][1] = $z * $y * (1 - cos($this->_angle)) + $x * sin($this->_angle);
		$this->_final_matrice[2][2] = $z * $z * (1 - cos($this->_angle)) + cos($this->_angle);
	}

	public static function doc() {
		return (file_get_contents("Matrix.doc.txt"));
	}
	public function __toString() {
		return ("ToSTRING not implemented");
	}
	public function __destruct() {
		print ('Function Matrix Destoyed by a giant ship' . PHP_EOL);
	}
	private function mult_mat()
	{}
}

$test = new Matrix(array('preset' => Matrix::TRANSLATION, 'vtc' => new Vector(array('x' => 10, 'y' => 10, 'z' => 10))));
$yolo = new Matrix(array('preset' => Matrix::RZ, 'angle' => pi()/2));
?>
