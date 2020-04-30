#!/bin/bash
filename='data.txt'
outfile='merci.sql'

type=('alimento' 'bevanda')

echo "" > $outfile

while read line; do
	code=`echo $line | cut -d' ' -f 1`
	price=`echo $line | rev | cut -d' ' -f 1 | rev`
	name=${line#"$code"}
	name=${name%"$price"}
	name=$(sed -E 's/^(\\t|[[:space:]])*//' <<<${name})
	name=$(sed -E 's/(\\t|[[:space:]])*$//' <<<${name})

	echo $code; echo $name; echo $price;
	echo -e "insert into merci(codice, nome, tipo) values(\"$code\", \"$name\", \"${type[$((RANDOM % 2))]}\");" >> $outfile
done < $filename
