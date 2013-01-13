#!/usr/bin/perl -pl

INIT {
  sub kmp {
    my $n = length @_;
    my @fail = (0);
    for my $i (1 .. $#_) {
      my $j = $fail[$i - 1];
      while ($j > 0 && $_[$j] ne $_[$i]) {
        $j = $fail[$j - 1];
      }
      push @fail, $_[$j] eq $_[$i] ? $j + 1 : 0;
    }
    @fail;
  }
}

@_ = kmp split //;
$_[0] = 0;
$_ = "@_";
