#!/bin/sh

INPUTS=("test ../test; echo Success" "test ../test && echo Success" "test ../test || echo failure" "test ../tes || echo Success")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

