<?PHP
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
date_default_timezone_set('Europe/Paris');


Class Tyrion extends Lannister {
	public function __construct(){
		parent::__construct();
		print ("My name is Tyrion".PHP_EOL);
	}
	public function getSize() {
		return "Short";
	}
}
?>
