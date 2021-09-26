#!/bin/bash
make bonus
while :
do
	ARG=$(./rand 5); ../push_swap $ARG | ../checker $ARG
done
