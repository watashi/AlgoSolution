gets
puts !/@/ || /^@|@.?@|@$/ ? 'No solution' : $_.gsub(/@.(?=.*@)/){$&+','}
__END__
WA8 !/@/
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230188 	Dec 27, 2010 12:23:32 PM 	watashi 	B - Sysadmin Bob 	Ruby 	Accepted 	80 ms 	2992 KB
