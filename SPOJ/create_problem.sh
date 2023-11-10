#!/bin/sh

pname=$1

fname=SPOJ_"$pname".cpp
cp "$TEMPLATE" "./$fname"

echo "CREATED $fname based on the default template"