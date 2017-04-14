<?PHP

if (!(isset($_POST['login'])) || !(isset($_POST['passwd'])) || !(isset($_POST['submit'])))
{
	echo "ERROR\n";
	return (0);
}
if ($_POST['submit'] != "OK")
{
	echo "ERROR\n";
	return (0);
}
if (!file_exists("../private"))
{
	if (system("mkdir ../private"))
	{
		echo "ERROR\n";
		return (0);
	}
}
$login = $_POST['login'];
$passwd = $_POST['passwd'];
$sel = "yoloswag";
if ($login == "" || $passwd == "")
{
	echo "ERROR\n";
	return (0);
}
if (file_exists("../private/passwd"))
{
	if (!($file = file_get_contents("../private/passwd")))
	{
		echo "ERROR\n";
		return (0);
	}
}

$passwd = hash("whirlpool", $passwd.$sel);
if ($file)
{
	$list = unserialize($file);
	foreach ($list as $elem)
	{
		if ($elem[0] === $login)
		{
			echo "ERROR\n";
			return (0);
		}
	}
	$list[] = array($login, $passwd);
	if (file_put_contents("../private/passwd",serialize($list)) === FALSE)
	{
		echo "ERROR\n";
		return (0);
	}
}
else
{
	if (file_put_contents("../private/passwd",serialize(array(array($login, $passwd))), FILE_APPEND) === FALSE)
	{
		echo "ERROR\n";
		return (0);
	}
}

?>
