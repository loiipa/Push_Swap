#!/bin/bash
make
while :
do
	ARG=$(./rand 5); ../push_swap $ARG | ./checker_Mac $ARG
done
