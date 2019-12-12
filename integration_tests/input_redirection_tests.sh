#!/bin/sh

INPUTS=("echo < unit_tests/inTest1.txt" "echo < unit_tests/fail.txt")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done
