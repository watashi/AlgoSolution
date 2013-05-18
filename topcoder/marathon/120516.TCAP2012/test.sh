for i in $*
do
	echo -e "\nTest $i:"
    #EXEC="tee data/$i.in"
	java -jar Tester.jar -exec "${EXEC:-./a.out}" -seed $i
done

# 193, 448, 520, 734
