chomp($_ = <STDIN>);
s/(.)\1*/\1/g;
$c = 'o';
while (length($_) > 1) {
    $c = $c eq 'o' ? 'x' : 'o';
    if (/^$c/) {
        s/^.//;
    } elsif (/$c$/) {
        s/.$//;
    }
}
print "$_\n";
