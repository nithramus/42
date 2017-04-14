#!/usr/bin/php
<?PHP
function ft_split($str)
{
	$splitter = explode(" ", $str);
	$array = array();
	foreach($splitter as $elem)
	{
		if ($elem)
			$array[] = $elem;
	}
	return ($array);
}
if ($argc != 2)
{
	return (0);
}
$ret = ft_split($argv[1]);
$i = 0;
foreach ($ret as $elem)
{
	if ($i == 0)
	{
		echo $elem;
		$i = 1;
	}
	else
	{
		echo " $elem";
	}
}
echo "\n";
?>
