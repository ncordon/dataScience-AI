#!/bin/bash
IFS=
echo "" > nonstop_pre.tex

while read -r line
do
    line=$(echo $line | sed 's/\\pause//g')
    line=$(echo $line | sed 's/\[<+\->\]//g')
    echo $line >> nonstop_pre.tex
   
done < ./presentacion.tex

echo $line >> nonstop_pre.tex
