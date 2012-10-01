#!perl -p
$n=$_;for$i(map{$n%$_?():($_,$n/$_)}1..40000){$_{$i}=1 if eval"y/$i/$i/"}$_=keys%_;
