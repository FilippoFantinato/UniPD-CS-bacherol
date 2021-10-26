#!/bin/bash
filename='data.txt';
outfile='operazioni-su-magazzini.sql';
fornitoriFile='fornitori.txt';

magazzino=1;
magazziniLength=22

OPERATIONS_NUMBER=20;

fornitori=();
for el in `cat $fornitoriFile`; do
	fornitori=("${fornitori[@]}" "$el")
done

merceCodes=();
mercePrices=();
while read line; do
	merceCodes=("${merceCodes[@]}" "`echo $line | cut -d' ' -f 1`");
	mercePrices=("${mercePrices[@]}" "`echo $line | rev | cut -d' ' -f 1 | rev`");
done < $filename;

echo "" > $outfile;

while [ $magazzino -lt $magazziniLength ]; do

	index=0;
	merceUsed=();

	while [ $index -lt $OPERATIONS_NUMBER ]; do

		ts=`date -d "$((RANDOM%3+2017))-$((RANDOM%12+1))-$((RANDOM%28+1)) $((RANDOM%23+1)):$((RANDOM%59+1)):$((RANDOM%59+1))" '+%Y-%m-%d %H:%M:%S'`

		if [ $index -lt $((OPERATIONS_NUMBER / 3 * 2)) ]; then
			merceIndex=$((RANDOM % ${#merceCodes[@]}));
			merceUsed=("${merceUsed[@]}" "$merceIndex");
			
			code=${merceCodes[$merceIndex]};
			price=${mercePrices[$merceIndex]};
			
			quantita=`shuf -i 100-150 -n 1`;
			saldo=`echo "$quantita * $price" | bc`;
			fornitore=${fornitori[$((RANDOM % ${#fornitori[@]}))]}
			

			if [ `echo "$saldo > 32767" | bc -l` -eq 1 ]; then
				saldo=32767
			fi

			echo -e "insert into carico(ts, magazzino, merce, quantita, saldato, saldo, fornitore) values(\"$ts\", $magazzino, \"$code\", $quantita, 0, $saldo, \"$fornitore\");" >> $outfile;
		else
			merceIndex=${merceUsed[$((RANDOM % ${#merceUsed[@]}))]};

			code=${merceCodes[$merceIndex]};
			price=${mercePrices[$merceIndex]};

			quantita=`shuf -i 10-25 -n 1`;
			saldo=`echo "$quantita * $price" | bc`;

			if [ `echo "$saldo > 32767" | bc -l` -eq 1 ]; then
				saldo=32767
			fi
			
			echo -e "insert into scarico(ts, magazzino, merce, quantita) values(\"$ts\", $magazzino, \"$code\", $quantita);" >> $outfile;
		fi

		index=$((index + 1));
	done

	magazzino=$((magazzino + 1));
done
