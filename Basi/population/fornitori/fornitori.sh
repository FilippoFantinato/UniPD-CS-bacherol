#!/bin/bash
filename='data.txt'
outfile='fornitori.sql'

state=('IT' 'US' 'UK' 'FR' 'ES' 'DE' 'BG' 'LT' 'AT')

echo "" > $outfile

while read line; do
	mail=`echo $line | rev | cut -d' ' -f 1 | rev`
	phone=`echo $line | rev | cut -d' ' -f 2 | rev`
	name=${line%"$mail"}
	name=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${name})
	name=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${name})
	name=${name%"$phone"}
	name=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${name})
	name=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${name})

	piva=${state[$((RANDOM % ${#state[@]}))]}`shuf -i 100000000-999999999 -n 1`
	
	echo $piva
	echo -e "insert into fornitori(piva, nome, mail, telefono) values(\"$piva\", \"$name\", \"$mail\", \"$phone\");" >> $outfile
done < $filename
