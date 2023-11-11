#!/bin/bash

output_file="time.txt"

gcc selection-sort.c -o selection-sort
for input_file in {1..6}.txt; do
    ./selection-sort < "$input_file" >> "$output_file"
    echo "$input_file"
done