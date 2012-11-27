#!perl -pl
INIT{$_ = <>}$:=y/:/:/;s/::/':'x(9-$:)/e if/::/;s/(?<!\w)\w*/'0'x(4-length$&).$&/ge
