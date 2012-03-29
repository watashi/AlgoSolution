for i in $@
do
    time ./a.out < $i.in > $i.out
    echo -e "\e[1;34m"
    ./check $i.in $i.out
    echo -e "\e[0m"
done
