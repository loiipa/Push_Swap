#!/bin/bash
make bonus
while :
do
	ARG=$(./rand 500); ../push_swap $ARG | ../checker $ARG
done
