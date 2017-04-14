<?PHP
function auth($login, $passwd)
{
if (!(isset($_POST['login'])) || !(isset($_POST['passwd'])))
	return (False);
if (!file_exists("../private"))
{
	return (False);
}
$sel = "yoloswag";
if ($login == "" || $passwd== "")
	return (False);
if (file_exists("../private/passwd"))
{
	if (!($file = file_get_contents("../private/passwd")))
	{
		return (False);
	}
}
else
	return (False);
$passwd = hash("whirlpool", $passwd.$sel);
if ($file)
{
	$list = unserialize($file);
	foreach ($list as $key => $elem)
	{
		if ($elem[0] == $login)
		{
			if ($elem[1] == $passwd)
			{
				return (True);
			}
			else
				return (False);
		}
	}
}
return (False);
?>
