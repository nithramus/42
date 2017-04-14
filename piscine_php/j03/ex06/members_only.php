<?PHP
if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW']))
	if($_SERVER['PHP_AUTH_USER'] == "zaz" && $_SERVER['PHP_AUTH_PW'] == "jaimelespetitsponeys")
	{
		echo "<html><body>\n";
		echo "Bonjour Zaz<br />\n";
		$img = base64_encode(file_get_contents("../img/42.png"));
		echo "<img src='data:image/png;base64, (../img/42.png)$img'>";
		echo "</body></html>";
		return (0);
	}
header("Connection: close");
echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
exit;
?>