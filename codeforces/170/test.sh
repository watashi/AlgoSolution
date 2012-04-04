for i in $@
do
    if [ ! -e data/$i.in ]
    then
        ./gen $i > data/$i.in
    fi
    time ./a.out < data/$i.in > data/$i.out
    echo -e "\e[1;34m"
    ./check data/$i.in data/$i.out
    echo -e "\e[0m"
done
