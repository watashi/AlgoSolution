r, c = gets.split.map(&:to_i)
a = Array.new(r){ gets.split.map(&:to_i) }
f = ->(a, b){ a.map{|_| y = _.send(b); _.map{|x| x == y} } }
x = f[a, :min]
y = f[a.transpose, :max]
r.times do |i|
    c.times do |j|
        if x[i][j] && y[j][i]
            p a[i][j]
            exit
        end
    end
end
puts "GUESS"

__END__
Correct Answer
Execution Time: 1.02
