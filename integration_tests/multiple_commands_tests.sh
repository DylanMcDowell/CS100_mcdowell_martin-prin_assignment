#!/bin/sh

INPUTS=("echo hello; echo world" "echo hello || echo world" "echo hello && echo world" "ls -a; echo hello || echo world; git status")

for input in  "${INPUTS[@]}"
do
	echo "./rshell, input: ${input}"
	./../rshell <<< ${input}
done
