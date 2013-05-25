for i in $*
do
	echo -e "\nTest $i:"
  #EXEC="tee data/$i.in"
	java -jar StringConnectivityVis.jar -exec "${EXEC:-./a.out}" -seed $i -novis
done
