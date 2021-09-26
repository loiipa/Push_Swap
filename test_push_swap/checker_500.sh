#!/bin/bash
make
while :
do
	ARG=$(./rand 500); ../push_swap $ARG | ./checker_Mac $ARG
done
