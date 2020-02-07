#!/bin/bash

outfile='prenotazioni-tavoli-agenzie.sql';

tavoli=();
tavoliFilename='tavoli.txt';

while read line; do
	tavoli=("${tavoli[@]}" "$line");
done < $tavoliFilename

prenotazioniAgenzieFilename='prenotazioni-agenzie.txt';
prenotazioniAgenzie=();

while read line; do
	people=`echo $line | cut -d',' -f 2`;
	people=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${people});
	people=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${people});

	prenotazioniAgenzie=("${prenotazioniAgenzie[@]}" "$people");
done < $prenotazioniAgenzieFilename

echo "" > $outfile;

for i in {1001..1100}; do
	peop=${prenotazioniAgenzie[$((i % 100))]};

	lastCodiceSede=0;

	while [[ $peop -ge 0 ]]; do
		tavolo=${tavoli[$((RANDOM % ${#tavoli[@]}))]};

		codiceSede=`echo $tavolo | cut -d',' -f 1`;
		codiceSede=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${codiceSede});
		codiceSede=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${codiceSede});

		if [[ $lastCodiceSede -eq 0 ]]; then
			lastCodiceSede=$codiceSede;
		fi

		if [[ $lastCodiceSede -eq $codiceSede ]]; then
			numeroSala=`echo $tavolo | cut -d',' -f 2`;
			numeroSala=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${numeroSala});
			numeroSala=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${numeroSala});

			numeroTavolo=`echo $tavolo | cut -d',' -f 3`;
			numeroTavolo=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${numeroTavolo});
			numeroTavolo=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${numeroTavolo});

			coperti=`echo $tavolo | cut -d',' -f 4`;
			coperti=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${coperti});
			coperti=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${coperti});

			peop=$((peop - coperti));

			echo "Done";

			echo -e "\t($i, \t$codiceSede, \t$numeroSala, \t$numeroTavolo)," >> $outfile;
		fi

	done
done
