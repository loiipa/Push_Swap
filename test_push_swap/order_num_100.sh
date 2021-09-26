#!/bin/bash
make
while :
do
	ARG=$(./rand 100); ../push_swap $ARG | wc -l
done
