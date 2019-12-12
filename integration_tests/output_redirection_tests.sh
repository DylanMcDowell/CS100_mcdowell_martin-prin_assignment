#!/bin/sh

INPUTS=("echo Hello World > integration_tests/outtestI1.txt" "echo Hello World >> integration_test/outtestI2.txt" "echo Hello Again >> integration_test/outtestI2.txt")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

