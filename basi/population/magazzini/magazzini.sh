#!/bin/bash
filename='data.txt'
outfile='magazzini.sql'

index=1

echo "" > $outfile

while read line; do
	echo -e "insert into magazzini(indirizzo, sedeAppartenenza) values(\"$line\", $index);" >> $outfile

	index=$((index + 1));
done < $filename
