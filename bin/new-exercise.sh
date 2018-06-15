#!/bin/bash

# From under reasonml: ./bin/new-exercise.sh <exercise-name>

# Creates a new exercise folder with the standard structure and empty test and example reason files.

cp -r ./template ./exercises
mv ./exercises/template ./exercises/$1
find ./exercises/$1/ -type f | xargs sed -i "s/"'$(name)'"/$1/g"
test_file=`echo $1_test.re | sed -e "s/\b\(.\)/\u\1/"`
touch ./exercises/$1/__tests__/$test_file
