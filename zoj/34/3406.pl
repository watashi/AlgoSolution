#!/usr/bin/perl -pal
s{[a-z]{3,}}{
    substr($&, 0, 1) .
    (length($&) - 2) .
    substr($&, -1)
}egix;

__END__
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
314     2010-10-05 22:23:56     Accepted    A   Perl    280     396     watashi@Zodiac  Source

# 2012-09-07 15:52:30 | Accepted | 3406 | Perl | 280 | 544 | watashi | Source
