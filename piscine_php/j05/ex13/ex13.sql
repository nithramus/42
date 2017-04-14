SELECT round(sum(nbr_siege) / (1 + max(id_salle))) as moyenne FROM salle;
