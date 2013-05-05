for i in $*
do
	echo -e "\nTest $i:"
  #EXEC="tee data/$i.in"
	java -jar FragileMirrorsVis.jar -exec "${EXEC:-./a.out}" -seed $i -novis
done
