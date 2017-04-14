#!/usr/bin/php
<?PHP
function tri($str1, $str2)
{
	$tri = "abcdefghijklmnopqrstuvwxyz0123456789 !\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~i";
	$split1 =strtolower($str1);
	$split2 =strtolower($str2);
	$i = 0;
	while ($split1[$i])
	{
		if (strpos($tri, $split1[$i]) != strpos($tri, $split2[$i]))
			return (strpos($tri, $split1[$i]) - strpos($tri, $split2[$i]));
		$i++;
	}
	return (0);
}

if ($argc < 2)
	return (0);

$array = array();
$j = 1;
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
$argv = $array;

$i = 0;
while ($i + 1 < count($argv))
{
	$value = tri($argv[$i], $argv[$i + 1]);
	if ($value > 0)
	{
		$swap = $argv[$i];
		$argv[$i] = $argv[$i + 1];
		$argv[$i + 1] = $swap;
		$i = 0;
	}
	else
		$i++;
}
$i = 0;
while ($i < count($argv))
{
	echo $argv[$i]."\n";
	$i++;
}

?>
