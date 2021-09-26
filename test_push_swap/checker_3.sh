#!/bin/bash
make
while :
do
	ARG=$(./rand 3); ../push_swap $ARG | ./checker_Mac $ARG
done
