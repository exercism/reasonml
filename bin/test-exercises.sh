test_run() {
    dic=$(mktemp -d)
    echo "Testing $1"
    cp -r $1 $dic
    source_file="$(jq -r '.files.solution[0]' $1/.meta/config.json)"
    cat "$1/.meta/src/Example.re" > "${dic}/$(basename $1)/${source_file}"
    pushd "$dic/$(basename $1)" > /dev/null
    npm i && npm run build && npm run test:ci || exit 1
    popd > /dev/null
}

for exercise in ./exercises/practice/*; do
    test_run ${exercise} 
done

if [ -d "./exercises/concept" ]; then
    for exercise in ./exercises/concept/*; do
        test_run ${exercise}
    done
fi