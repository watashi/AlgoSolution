#!perl -p
INIT{<>}$:=y/:/:/;s/::/':'x(9-$:)/e;s/\w*\W/0 x(5-length$&).$&/ge
