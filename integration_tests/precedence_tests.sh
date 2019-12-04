#!/bin/sh

INPUTS=("(echo A && echo B) || (echo C && echo D)" "echo A || (echo B && exit); echo Success")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

