insert into contenimento(magazzino, merce, quantitaGiacenza)
	select magazzino, merce, sum(quantita) as quantitaGiacenza from (
		select magazzino, merce, -1 * cast(quantita as signed) as quantita from scarico
		union
		select magazzino, merce, quantita from carico
	) t group by magazzino, merce;

-- select magazzino, merce, sum(quantita) from (
-- 	select magazzino, merce, -1 * cast(quantita as signed) as quantita from scarico
-- 	union
-- 	select magazzino, merce, quantita from carico
-- ) t group by magazzino, merce;
