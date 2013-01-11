#!/usr/bin/perl

undef $/;

my %tab = ();
$_ = <DATA>;
@_ = split;
while (@_ > 0) {
  my $k = pop @_;
  pop @_;
  ++$tab{$k};
}

my $ans = $tab{Stop};
my $mod = 1_000_000;
$_ = <>;
while (/\w/g) {
  $ans = $ans * $tab{$&} % $mod;
}
print "$ans\n";

__DATA__
UUU F      CUU L      AUU I      GUU V
UUC F      CUC L      AUC I      GUC V
UUA L      CUA L      AUA I      GUA V
UUG L      CUG L      AUG M      GUG V
UCU S      CCU P      ACU T      GCU A
UCC S      CCC P      ACC T      GCC A
UCA S      CCA P      ACA T      GCA A
UCG S      CCG P      ACG T      GCG A
UAU Y      CAU H      AAU N      GAU D
UAC Y      CAC H      AAC N      GAC D
UAA Stop   CAA Q      AAA K      GAA E
UAG Stop   CAG Q      AAG K      GAG E
UGU C      CGU R      AGU S      GGU G
UGC C      CGC R      AGC S      GGC G
UGA Stop   CGA R      AGA R      GGA G
UGG W      CGG R      AGG R      GGG G
