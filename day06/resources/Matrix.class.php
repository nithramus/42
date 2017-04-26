<?PHP
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
			$this->scalee();
		else if ($this->_preset == self::PROJECTION)
			$this->_projection($this->_fov, $this->_ratio, $this->_near, $this->_far);
		if (self::$verbose === True)
			print("Matrix instance constructed" . PHP_EOL);
	}
	private function translation(){
		$this->_final_matrice[0][3] += $this->_vtc->get_x();
		$this->_final_matrice[1][3] += $this->_vtc->get_y();
		$this->_final_matrice[2][3] += $this->_vtc->get_z();
		$this->_final_matrice[3][3] += $this->_vtc->get_w();
	}

	private function scalee() {
		for ($i = 0; $i < 3; $i++)
		{
			for ($j = 0; $j < 4; $j++)
			{
				$this->_final_matrice[$i][$j] *= $this->_scale;
			}
		}
	}
	private function _projection( $fov, $ratio, $near, $far) {
		$scale = tan(deg2rad($fov * 0.5)) * $near;
		$right = $ratio * $scale;
		$left = -$right;
		$top = $scale;
		$bottom = -$top;
		self::_OpenGLFrustrum($left, $right, $bottom, $top, $near, $far);
	}

	private function _OpenGLFrustrum($left, $right, $bottom, $top, $near, $far) {
		$this->_final_matrice[0][0] = (2 * $near) / ($right - $left);
		$this->_final_matrice[0][1] = 0;
		$this->_final_matrice[0][2] = ($right + $left) / ($right - $left);
		$this->_final_matrice[0][3] = 0;
		$this->_final_matrice[1][0] = 0;
		$this->_final_matrice[1][1] = (2 * $near) / ($top - $bottom);
		$this->_final_matrice[1][2] = ($top + $bottom) / ($top - $bottom);
		$this->_final_matrice[1][3] = 0;
		$this->_final_matrice[2][0] = 0;
		$this->_final_matrice[2][1] = 0;
		$this->_final_matrice[2][2] = -(($far + $near) / ($far - $near));
		$this->_final_matrice[2][3] = -((2 * $far * $near) / ($far - $near));
		$this->_final_matrice[3][0] = 0;
		$this->_final_matrice[3][1] = 0;
		$this->_final_matrice[3][2] = -1;
		$this->_final_matrice[3][3] = 0;
	}
	private function identity() {
		return (0);
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
		$string = "";
		foreach ($this->_final_matrice as $tab)
		{
			foreach ($tab as $elem)
			{
				$string = $string . $elem. ' ; ';
			}
			$string = $string . PHP_EOL;
		}
		return ($string);
	}
	public function __destruct() {
		print ('Function Matrix Destoyed by a giant ship' . PHP_EOL);
	}
	public function mult(Matrix $mat)
	{
		$new = new Matrix(array('preset' => Matrix::IDENTITY));
		for ($i = 0; $i < 4; $i++)
		{
			for ($j = 0; $j < 4; $j++)
			{
				$new->_final_matrice[$i][$j] = 0;
				for ($k = 0; $k < 4; $k++)
				{
					$new->_final_matrice[$i][$j] += $this->_final_matrice[$i][$k] * $mat->_final_matrice[$k][$j];
				}
			}
		}
		return ($new);
	}
	public function transformVertex(Vertex $vertex)
	{
		$value = array($vertex->get_x(), $vertex->get_y(), $vertex->get_z(), $vertex->get_w());
		$stock = array(0,0,0,0);
		print_r($value);
		print_r($this->_final_matrice);
		for ($i = 0; $i < 4; $i++)
		{
			for ($k = 0; $k < 4; $k++)
			{
				$stock[$i] += $this->_final_matrice[$i][$k] * $value[$k];
			}
		}
		return (new Vertex(array('x' => $stock[0],'y' => $stock[1],'z' => $stock[2],'w' => $stock[3])));
	}

}

//$test = new Matrix(array('preset' => Matrix::TRANSLATION, 'vtc' => new Vector(array('x' => 10, 'y' => 10, 'z' => 10))));
//$yolo = new Matrix(array('preset' => Matrix::RZ, 'angle' => pi()/2));
?>
