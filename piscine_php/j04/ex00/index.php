<?PHP

session_start();
if (isset($_GET['submit']))
{
	if ($_GET['submit'] == "OK")
	{
		if (isset($_GET['login']))
			$_SESSION['login'] = $_GET['login'];
		if (isset($_GET['passwd']))
			$_SESSION['passwd'] = $_GET['passwd'];
	}
}


?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"/>
	<title>Members Only</title>
</head>
<body>
<p> Nom d'utilisateur</p>
<form method="get" action="index.php">
	<label>Pseudo</label><input type="text" name="<?PHP if(isset($_SESSION["login"])){$_SESSION["login"];}?>"/><br>
	<label>mot de passe</label><input type="text" name="<?PHP if(isset($_SESSION["passwd"])){echo $_SESSION["passwd"];}?>"/><br>
	<input type="submit" name="submit" value="OK"/>
</form>
<p> bonne chance</p>
</body>
</html>
