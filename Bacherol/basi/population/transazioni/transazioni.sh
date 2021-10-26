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

RICEVUTE_NUMBER=150;

index=1;
ricevuteOutfile='ricevute.sql';

ricevuteForYear=();

echo "" > $ricevuteOutfile;

while [ $index -le $RICEVUTE_NUMBER ]; do

	date=`generateDate`;
	year=`echo $date | cut -d'-' -f 1`;
	sede=$((RANDOM % 22 + 1));
	saldo=`shuf -i 1-1000 -n 1`;
	contributi=$((saldo * 30 / 100));

	[[ -z ${ricevuteForYear[$year]+x} ]] && ricevuteForYear[$year]=1 || ricevuteForYear[$year]=$((${ricevuteForYear[$year]} + 1));

	echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $sede, 'R', $saldo, $contributi);" >> $outfile;
	echo "insert into ricevute(ts, codiceSede, progressivoRicevute) values(\"$date\", $sede, ${ricevuteForYear[$year]});" >> $ricevuteOutfile;

	index=$((index + 1));	
done

echo "" >> $outfile;

# Fatture

FATTURE_NUMBER=150;

index=1;
fattureOutfile='fatture.sql';

fattureForYear=();
agenzieFilename='agenzie.txt';

agenzie=();
for el in `cat $agenzieFilename`; do
	agenzie=("${agenzie[@]}" "$el");
done

echo "" > $fattureOutfile;

while [ $index -le $FATTURE_NUMBER ]; do

	date=`generateDate`;
	year=`echo $date | cut -d'-' -f 1`;
	sede=$((RANDOM % 22 + 1));
	saldo=`shuf -i 400-8000 -n 1`;
	contributi=$((saldo * 30 / 100));

	agenzia=${agenzie[$((RANDOM % ${#agenzie[@]}))]};

	[[ -z ${fattureForYear[$year]+x} ]] && fattureForYear[$year]=1 || fattureForYear[$year]=$((${fattureForYear[$year]} + 1));

	echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $sede, 'F', $saldo, $contributi);" >> $outfile;
	echo "insert into fatture(ts, codiceSede, progressivoFatture, agenzia) values(\"$date\", $sede, ${fattureForYear[$year]}, \"$agenzia\");" >> $fattureOutfile;

	index=$((index + 1));
done

echo "" >> $outfile;

# Esborsi

ESBORSI_NUMBER=150;

index=1;
esborsiOutfile='esborsi.sql';

carichiFilename='carichi.txt';

echo "" > $esborsiOutfile;

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

		econtributi=`echo "$saldo * 30 / 100" | bc`;
		saldo=`echo "-1 * $saldo" | bc`;

		echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $idMagazzinoSede, 'E', $saldo, $contributi);" >> $outfile;
		echo "insert into pagamento(tsCarico, magazzino, tsTransazione, codiceSede) values(\"$dateCarico\", $idMagazzinoSede, \"$date\", $idMagazzinoSede);" >> $esborsiOutfile;
	fi
done < $carichiFilename

echo "" >> $outfile;

# Retribuzioni

RETRIBUZIONI_NUMBER=150;

index=1;
retribuzioniOutfile='retribuzioni.sql';

dipendentiFilename='dipendenti.txt';

dipendentiSedi=();
dipendentiCF=();
dipendentiStipendi=();
while read line; do
	sede=`echo $line | cut -d' ' -f 1`;
	CF=`echo $line | cut -d' ' -f 2`;
	stipendio=`echo $line | cut -d' ' -f 3`;

	dipendentiSedi=("${dipendentiSedi[@]}" "$sede");
	dipendentiCF=("${dipendentiCF[@]}" "$CF");
	dipendentiStipendi=("${dipendentiStipendi[@]}" "$stipendio");
done < $dipendentiFilename

echo "" > $retribuzioniOutfile;

while [ $index -le $RETRIBUZIONI_NUMBER ]; do

	date=`generateDate`;

	dipendenteIndex=$((RANDOM % ${#dipendentiCF[@]}));
	dipendente=${dipendentiCF[$dipendenteIndex]};
	sede=${dipendentiSedi[$dipendenteIndex]};

	saldo=${dipendentiStipendi[$dipendenteIndex]};
	contributi=`echo "$saldo * 30 / 100" | bc`;
	saldo=`echo "-1 * $saldo" | bc`;

	echo "insert into transazioni(ts, codiceSede, tipologia, saldo, contributi) values(\"$date\", $sede, 'S', $saldo, $contributi);" >> $outfile;
	echo "insert into retribuzioni(ts, codiceSede, dipendente) values(\"$date\", $sede, \"$dipendente\");" >> $retribuzioniOutfile;
	
	index=$((index + 1));

done
