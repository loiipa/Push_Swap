#!/bin/bash
make bonus
while :
do
	ARG=$(./rand 100); ../push_swap $ARG | ../checker $ARG
done
