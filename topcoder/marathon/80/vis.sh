for i in $*
do
	echo -e "\nTest $i:"
	java -jar FragileMirrorsVis.jar -exec "${EXEC:-./a.out}" -seed $i
done
