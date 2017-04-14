#!/usr/bin/php
<?PHP
function list_words($str)
{
	$splitter = explode(" ", $str);
	foreach($splitter as $elem)
	{
		if ($elem)
		{
			$array[] = $elem;
		}
	}
	return ($array);
}
if ($argc < 2)
	return (0);
$array = list_words($argv[1]);
$i = count($array) - 1;
echo $array[$i];
$j = 0;
while ($j < $i)
{
	echo " " .$array[$j];
	$j++;
}
echo "\n";
?>
