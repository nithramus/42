#!/usr/bin/php
<?PHP
if ($argc != 2)
{
	echo "Error";
	return (0);
}
if (!($file = fopen("$argv[1]", 'r+')))
{
	echo "Error";
	return (0);
}
$doc = "";
while ($read = fread($file, 50))
{
	$doc = $doc . $read;
}

if (preg_match("#(<a .*?>((.*?)+?)<.*?\/a>)+#i", $doc, $array))
	echo ("true\n");
print_r($array);


if (preg_match("#<a .*?<\/a>#", $doc, $array))
	echo "Vraie\n";
print_r($array);

echo "$doc";
preg_match("#(.*?title=\"(.*?)\")(.*?title=\"(.*?)\"#", $array[0], $array);
print_r($array);

?>
