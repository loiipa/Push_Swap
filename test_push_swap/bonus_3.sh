#!/bin/bash
make bonus
while :
do
	ARG=$(./rand 3); ../push_swap $ARG | ../checker $ARG
done
