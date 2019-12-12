#!/bin/sh

INPUTS=("cat < integration_tests/pipeIn | tr A-Z a-z | tee integration_tests/pipeOut1 | tr a-z A-Z > integration_tests/pipeOut2.txt", "ls | echo")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

