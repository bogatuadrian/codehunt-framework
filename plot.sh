#!/bin/sh

for t in $(ls "test"*".out")
do
	test_no=$(echo $t | sed -e 's/test//g' | sed -e 's/\.out//g')
	tt=$(echo $t | sed -e 's/\.out//g')
	gnuplot -e 'set term png; set output "'$tt'.png''"; plot "'$t'" with lines'
done
