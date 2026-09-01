#!/usr/bin/env bash

test_run() (
    exercise=$1
    tmp_dir=$(mktemp -d) || exit 1
    trap 'rm -rf -- "$tmp_dir"' EXIT

    echo "Testing $exercise"
    cp -r "$exercise" "$tmp_dir" || exit 1

    source_file=$(jq -er '.files.solution[0]' "$exercise/.meta/config.json") || exit 1

    exercise_dir="$tmp_dir/$(basename "$exercise")"
    cp "$exercise/.meta/src/Example.re" "$exercise_dir/$source_file" || exit 1

    cd "$exercise_dir" || exit 1
    npm ci --loglevel=error --no-audit --no-fund > /dev/null &&
        npm run --silent build &&
        npm run --silent test:ci
)

for exercise in ./exercises/practice/*; do
    test_run "$exercise" || exit 1
done

if [ -d "./exercises/concept" ]; then
    for exercise in ./exercises/concept/*; do
        test_run "$exercise" || exit 1
    done
fi