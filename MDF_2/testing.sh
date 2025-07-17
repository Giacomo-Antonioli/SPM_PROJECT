#!/bin/bash
tasks=( 10 100 1000 10000 100000 )
cycles=( 10 100 1000 10000 100000 )
minT=1
maxT=112
echo "Tasks, Cycles, Workers, Time">>${1}.txt
for i in "${tasks[@]}"
do
for j in "${cycles[@]}"
do
for k in $(eval echo "{$minT..$maxT}")
do

	./main $j $i $k>>  ${1}.txt
done
done
done
