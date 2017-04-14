<?PHP
function ft_is_sort($tab)
{
	$tab_bis = $tab;
	sort($tab_bis);
	if ($tab_bis == $tab)
		return (TRUE);
	else
		return (False);
}
