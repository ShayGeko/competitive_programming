#!/bin/sh

pnum=$1
pname=$2

fname=BOJ_"$1"_"$2".cpp
cp "$TEMPLATE" "./$fname"

echo "CREATED $fname based on the default template"