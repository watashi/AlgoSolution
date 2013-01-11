package Rosalind;

use strict;
use warnings;
use Exporter;

our @ISA = qw(Exporter);
our @EXPORT_OK = qw(%codon %nodoc revc);

# RNA codon table
our $codon =<<EOF;
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
UAA 0      CAA Q      AAA K      GAA E
UAG 0      CAG Q      AAG K      GAG E
UGU C      CGU R      AGU S      GGU G
UGC C      CGC R      AGC S      GGC G
UGA 0      CGA R      AGA R      GGA G
UGG W      CGG R      AGG R      GGG G
EOF

our %codon = split ' ', $codon;
our %nodoc = ();

while (my ($k, $v) = each %codon) {
  $nodoc{$v} ||= [];
  push $nodoc{$v}, $k;
}

# reverse complement
sub revc {
  my $_ = shift;
  y/ACGT/TGCA/;
  reverse;
}

1;
