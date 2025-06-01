#!/bin/bash

# From under reasonml: ./bin/new-exercise.sh <exercise-name>

# Creates a new exercise folder with the standard structure and empty test and example reason files.

cp -r ./template ./exercises
mv ./exercises/template ./exercises/$1
