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
	sort($array, SORT_STRING);
	return ($array);
}
?>
