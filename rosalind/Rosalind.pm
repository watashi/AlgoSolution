package Rosalind;

use strict;
use warnings;
use Exporter;

our @ISA = qw(Exporter);
our @EXPORT_OK = qw(%codon %nodoc revc fasta mass spect);

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
  scalar reverse;
}

# read fasta
sub fasta {
  my $_ = shift;
  my @ret = ();
  while (/(?:^>(\w+).*$)((?:\R^(?!>).*$)*)/mg) {
    my $key = $1;
    my $value = $2;
    push @ret, $key, $value =~ s/\s//gr;
  }
  @ret;
}

# Monoisotopic mass table
our $mass = <<EOF;
A   71.03711
C   103.00919
D   115.02694
E   129.04259
F   147.06841
G   57.02146
H   137.05891
I   113.08406
K   128.09496
L   113.08406
M   131.04049
N   114.04293
P   97.05276
Q   128.05858
R   156.10111
S   87.03203
T   101.04768
V   99.06841
W   186.07931
Y   163.06333
EOF

our %mass = split ' ', $mass;

sub mass {
  my $mass = 0;
  for (split //, $_[0]) {
    $mass += $mass{$_};
  }
  $mass;
}

sub spect {
  my $mass = shift;
  my $eps = 1e10;
  my $ret = undef;
  keys %mass;
  while (my ($k, $v) = each %mass) {
    if (abs($mass - $v) < $eps) {
      ($eps, $ret) = (abs($mass - $v), $k);
    }
  }
  $eps < 1e-3 ? $ret : undef;
}

1;
