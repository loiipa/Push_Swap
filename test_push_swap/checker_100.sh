#!/bin/bash
make
while :
do
	ARG=$(./rand 100); ../push_swap $ARG | ./checker_Mac $ARG
done
