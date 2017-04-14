#!/usr/bin/php
<?PHP
date_default_timezone_set('Europe/Paris');
if ($argc != 2)
	return (0);
$str = $argv[1];
if (!preg_match("#([lL]undi |[Mm]ardi |[Mm]ercredi |[Jj]eudi |[Vv]endredi |[Ss]amedi |[Dd]imanche )([\d]{1,2}) ([Jj]anvier|[Ff]evrier|[mM]ars|[Aa]avril|[Mm]ai|[jJ]uin|[Jj]uillet|[aA]out|[Ss]eptembre|[Oo]ctobre|[nN]ovembre|[dD]ecembre) ([\d]{4}) ([\d]{2}):([\d]{2}):([\d]{2})#", $str, $array))
{
	echo "Wrong Format\n";
	return (0);
}

$mois = array("janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre");
$array[3] = strtolower($array[3]);

$i = 0;
while ($i < 12)
{
	if (strcmp($array[3], $mois[$i]) == 0)
		break;
	$i++;
}
$i++;
echo $i;
echo mktime($array[5],$array[6],$array[7],$i,$array[2],$array[4]). "\n";
?>
