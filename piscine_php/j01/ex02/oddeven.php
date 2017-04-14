#!/usr/bin/php
<?PHP
echo "Entrez un nombre: ";
while (fscanf(STDIN, "%s\n", $number))
{
	if (is_numeric($number) == 0)
	{
		echo "'$number' n'est pas un chiffre\n";
	}
	else
	{
		if ($number % 2 == 0)
		{
			echo "Le chiffre $number est Pair\n";
		}
		else
		{
			echo "Le chiffre $number est Impair\n";
		}
	}
	$number = " ";
	echo "Entrez un nombre: ";
}
 ?>
