SELECT SUM(nbr_siege) FROM salle GROUP BY etage_salle ORDER BY SUM(nbr_siege) DESC;
