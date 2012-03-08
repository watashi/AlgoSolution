n = gets.to_i
a = gets.split.map(&:to_i).sort.reverse
b = []
a.each do |_|
    b << _
    if a.inject(&:+) < b.inject(&:+) * 2
        p b.size
        break
    end
end
