#!/bin/bash

mins=(15 30 45 00)

outfile='prenotazioni-agenzie.sql';

generateDate()
{
	[[ -z ${1+x} ]] && year=$((RANDOM%4+2017)) || year=$1;

	echo `date -d "$year-$((RANDOM%12+1))-$((RANDOM%28+1)) $((RANDOM%13+10)):$((${mins[$RANDOM%4]})):00" '+%Y-%m-%d %H:%M:%S'`
}

agenzie=();
agenzieFilename='agenzie.txt';

for el in `cat $agenzieFilename`; do
	agenzie=("${agenzie[@]}" "$el");
done

echo "" > $outfile;

for i in {1..100}
do
	people=`shuf -i 10-100 -n 1`
	date=`generateDate`;

	oraInizio=`date -d "$date" '+%H:%M:%S'`;
	oraFine=`date -d "$date + 1 hour" '+%H:%M:%S'`;
	agenzia=${agenzie[$((RANDOM % ${#agenzie[@]}))]}

	echo -e "\t(\"$date\", \t\"$oraInizio\", \t\"$oraFine\", \t$people, \t\"$agenzia\")," >> $outfile;
done
