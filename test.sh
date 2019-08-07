set -e
for f in data/*-*
do
    echo '===' testing $f ...
    (cd $f && make)
done
