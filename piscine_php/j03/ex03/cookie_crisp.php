<?PHP
if (isset($_GET['action']) AND isset($_GET['name']))
{
	if ($_GET['action'] == "set" && isset($_GET['value']))
	{
		setcookie($_GET["name"], $_GET["value"], time() + 24 * 3600);
	}
	else if ($_GET['action'] == 'get')
	{
		$var = $_COOKIE[$_GET['name']];
		if ($var)
			echo $var."\n";
	}
	else if ($_GET['action'] == 'del')
	{
		setcookie($_GET['name'], '', time() - 3600);
	}
}
else
{
	echo "Arguments error: don't play this game with me\n";
}

?>
