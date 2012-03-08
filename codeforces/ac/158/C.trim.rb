p='/'
gets.to_i.times{|_|
gets
/cd /?(p=File.expand_path($'.chop,p)):puts((p[/(\/\w+)+/]||'')+'/')
}
