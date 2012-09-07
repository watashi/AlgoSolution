#!/usr/bin/perl -pal
/\[\s*(\d+)\s*:\s*(\d+)\s*\]\s*=\s*/ and
    $_ = join ', ', splice @a, $1, $2 - $1, map {int $_} split /[^-\d+]+/, $'

__END__
Run ID  Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
403     2010-11-11 23:15:44     Accepted    A   Perl    10  544     watashi@Zodiac  Source

# 2012-09-07 15:53:55 | Accepted | 3427 | Perl | 30 | 676 | watashi | Source
