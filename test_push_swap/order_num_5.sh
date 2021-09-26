#!/bin/bash
make
while :
do
	ARG=$(./rand 5); ../push_swap $ARG | wc -l
done
