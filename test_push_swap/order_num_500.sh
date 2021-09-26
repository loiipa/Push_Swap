#!/bin/bash
make
while :
do
	ARG=$(./rand 500); ../push_swap $ARG | wc -l
done
