#!/bin/bash
JAR='Wasabi v1_4/Wasabi v1_4.jar'
if [[ -e "$1" ]]
then
	java -jar "$JAR" < "$1"
else
	java -jar "$JAR" &
fi
