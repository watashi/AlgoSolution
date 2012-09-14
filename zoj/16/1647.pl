#!perl -nl
if (m#^//PROGRAMBEGIN#) {
    $in = 1;
    %re = ();
    next;
} elsif (!$in) {
    next;
} elsif (m#^//PROGRAMEND#) {
    $in = 0;
    $_ = '-' x 20;
} elsif (m/^#define\s+(\w+)\s*/) {
    $re{$1} = $';
} elsif (m/^#undef\s+(\w+)/) {
    delete $re{$1};
} else {
    for $k (sort {$b cmp $a} keys %re) {
        s/\b$k\b/$re{$k}/g;
    }
}
print;

__END__
## 这题题意完全不清！！！
Run ID  Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
2371654     2010-12-15 16:39:00     Accepted    1647    Perl    20  396     watashi@Zodiac  Source

# 2012-09-07 00:56:52 | Accepted | 1647 | Perl | 10 | 544 | watashi | Source
