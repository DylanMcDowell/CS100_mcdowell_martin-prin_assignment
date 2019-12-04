#!/bin/sh

INPUTS=("exit; echo failure" "ech fail || exit; echo failure")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

