#!/bin/bash
# types: 'A', 'R', 'F', 'S', 'E'

outfile='transazioni.sql';

generateDate()
{
	[[ -z ${1+x} ]] && year=$((RANDOM%3+2017)) || year=$1;

	echo `date -d "$year-$((RANDOM%12+1))-$((RANDOM%28+1)) $((RANDOM%23+1)):$((RANDOM%59+1)):$((RANDOM%59+1))" '+%Y-%m-%d %H:%M:%S'`
}

echo "" > $outfile;

# Ricevute

# RICEVUTE_NUMBER=150;

# index=1;
# ricevuteForYear=();

# while [ $index -le $RICEVUTE_NUMBER ]; do

# 	date=`generateDate`;
# 	year=`echo $date | cut -d'-' -f 1`;
# 	sede=$((RANDOM % 22));
# 	saldo=`shuf -i 1-1000 -n 1`;
# 	contributi=$((saldo * 30 / 100));

# 	[[ -z ${ricevuteForYear[$year]+x} ]] && ricevuteForYear[$year]=1 || ricevuteForYear[$year]=$((${ricevuteForYear[$year]} + 1));

# 	echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $sede, 'R', $saldo, $contributi)" >> $outfile;
# 	echo "insert into ricevute(ts, codiceSede, progressivoRicevute) values(\"$date\", $sede, ${ricevuteForYear[$year]})" >> $outfile;

# 	index=$((index + 1));	
# done

# # Fatture

# FATTURE_NUMBER=150;

# index=1;
# fattureForYear=();

# while [ $index -le $FATTURE_NUMBER ]; do

# 	date=`generateDate`;
# 	year=`echo $date | cut -d'-' -f 1`;
# 	sede=$((RANDOM % 22));
# 	saldo=`shuf -i 400-8000 -n 1`;
# 	contributi=$((saldo * 30 / 100));

# 	[[ -z ${fattureForYear[$year]+x} ]] && fattureForYear[$year]=1 || fattureForYear[$year]=$((${fattureForYear[$year]} + 1));

# 	echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $sede, 'F', $saldo, $contributi)" >> $outfile;
# 	echo "insert into fatture(ts, codiceSede, progressivoFatture, agenzia) values(\"$date\", $sede, ${fattureForYear[$year]}, 'NULL')" >> $outfile;

# 	index=$((index + 1));
# done

# Esborsi

ESBORSI_NUMBER=150;

index=1;
carichiFilename='carichi.txt';


while read line; do
	if [[ "$((RANDOM % 2))" != "1" ]]; then
		saldo=`echo $line | rev | cut -d' ' -f 1 | rev`;
		idMagazzinoSede=`echo $line | rev | cut -d' ' -f 2 | rev`;
		dateCarico=${line%"$saldo"};
		dateCarico=$(sed -E 's/(\\t|[[:space:]])*$//' <<< ${dateCarico});
		dateCarico=${dateCarico%"$idMagazzinoSede"};
		dateCarico=$(sed -E 's/(\\t|[[:space:]])*$//' <<< ${dateCarico});

		date=`generateDate`;

		while [ `date -d "$dateCarico" +%s` -gt `date -d "$date" +%s` ]; do
			date=`generateDate`;
		done

		contributi=$((saldo * 30 / 100));
		saldo=$((-1 * saldo));

		echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $idMagazzinoSede, 'E', $saldo, $contributi)" >> $outfile;
		echo "insert into pagamento(tsCarico, magazzino, tsTransazione, codiceSede) values(\"$dateCarico\", $idMagazzinoSede, \"$date\", $idMagazzinoSede)" >> $outfile;
	fi
done < $carichiFilename

# Retribuzioni

RETRIBUZIONI_NUMBER=150;

index=1;
dipendentiFilename='dipendenti.txt';

dipendenti=();
for el in `cat $dipendentiFilename`; do
	dipendenti=("${dipendenti[@]}" "$el");
done

while [ $index -le $RETRIBUZIONI_NUMBER ]; do

	date=`generateDate`;
	sede=$((RANDOM % 22));

	saldo=`shuf -i 1000-2000 -n 1`;
	contributi=$((saldo * 30 / 100));
	saldo=$((-1 * saldo));

	dipendente=${dipendenti[$((RANDOM % ${#dipendenti[@]}))]};

	echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $sede, 'S', $saldo, $contributi)" >> $outfile;
	echo "insert into pagamento(ts, codiceSede, dipendente) values(\"$date\", $sede, \"$dipendente\")" >> $outfile;
	
	index=$((index + 1));

done
