#!/bin/bash

mkdir -p .build
read project
pdflatex $project.tex
mv $(ls | grep -v $project.pdf) ./.build
mv ./.build/clean-build.sh ./

