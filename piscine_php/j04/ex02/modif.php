<?PHP

if (!(isset($_POST['login'])) || !(isset($_POST['oldpw'])) || !(isset($_POST['submit']) || !(isset($_POST['newpw']))))
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
$oldpw = $_POST['oldpw'];
$newpw = $_POST['newpw'];
$sel = "yoloswag";
if ($login == "" || $oldpw == "" || $newpw == "")
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
$newpw = hash("whirlpool", $newpw.$sel);
$oldpw = hash("whirlpool", $oldpw.$sel);
if ($file)
{
	$list = unserialize($file);
	foreach ($list as $key => $elem)
	{
		if ($elem[0] == $login)
		{
			if ($elem[1] == $oldpw)
			{
				$list[$key][1] = $newpw;
				file_put_contents("../private/passwd",serialize($list));
				echo "OK\n";
				return (1);
			}
			else
			{
				echo "ERROR\n";
				return (0);
			}
		}
	}
}
echo "ERROR\n";
return (0);
?>
