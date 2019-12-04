#!/bin/sh

INPUTS=("echo hello#; echo world" "echo hello; echo #world" "e#cho hello; echo world")

for input in  "${INPUTS[@]}"
do
        echo "./rshell, input: ${input}"
        ./../rshell <<< ${input}
done

