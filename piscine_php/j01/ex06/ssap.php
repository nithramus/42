#!/usr/bin/php
<?PHP
$j = 1;
$array = array();
while ($j < $argc)
{
	$splitter = explode(" ", $argv[$j]);
	foreach($splitter as $elem)
	{
		if ($elem)
		{
			$array[] = $elem;
		}
	}
	$j++;
}
sort($array, SORT_STRING);
foreach($array as $elem)
{
	echo "$elem\n";
}
?>
