#!perl -n
use List::Util 'max';
END{print max values%_}++$_{$_}
