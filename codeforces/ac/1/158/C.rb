p = '/'
gets.to_i.times do |_|
    gets
    if /cd /
        p = File.expand_path($'.chop, p);
    else
        puts (p[/(\/\w+)+/] || '') + '/'
    end
end
