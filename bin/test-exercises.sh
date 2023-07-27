test_run() {
    dic=$(mktemp -d)
    echo "Testing $1"
    source_file="$(jq -r '.files.solution[0]' $1/.meta/config.json)"
    test_file="$(jq -r '.files.test[0]' $1/.meta/config.json)"
    echo "source_file: ${source_file}"
    cat "$1/.meta/src/Example.re" > "${dic}/${source_file}"
    cat "$1/${test_file}" > "${dic}/${test_file}"
    npm i && npm run build && npm run test:ci || exit 1
}

for exercise in ./exercises/practice/*; do
    test_run ${exercise} 
done

if [ -d "./exercises/concept" ]; then
    for exercise in ./exercises/concept/*; do
        test_run ${exercise}
    done
fi