SELECT COUNT(id_film) as film FROM historique_membre WHERE (date BETWEEN '2006/10/29' AND '2007/07/27') OR (MONTH(date) = 12 && DAY(date) = 24);
