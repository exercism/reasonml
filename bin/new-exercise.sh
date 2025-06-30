#!/bin/bash

# From under reasonml: ./bin/new-exercise.sh <exercise-name>

# Creates a new exercise folder with the standard structure and empty test and example reason files.

cp -r ./template ./exercises
mv ./exercises/template ./exercises/$1
find ./exercises/$1/ -type f | xargs sed -i "s/"'$(name)'"/$1/g"
lib_file=`echo $1.re | sed -e "s/\b\(.\)/\u\1/"`
test_file=`echo $1_test.re | sed -e "s/\b\(.\)/\u\1/"`
mv ./exercises/$1/lib/Example.re ./exercises/$1/lib/$lib_file
mv ./exercises/$1/test/Example_test.re ./exercises/$1/test/$test_file
