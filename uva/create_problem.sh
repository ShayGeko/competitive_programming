#!/bin/sh

pnum=$1
pname=$2

fname=UVA_"$1"_"$2".cpp
cp "$TEMPLATE" "./$fname"

echo "CREATED $fname based on the default template"