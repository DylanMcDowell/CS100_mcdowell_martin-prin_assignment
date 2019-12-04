#!/bin/sh

INPUTS=("test ../test" "test -f ../test " "test -d ../integration_tests" "test -d ../test" "test -f ../integration_tests")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

