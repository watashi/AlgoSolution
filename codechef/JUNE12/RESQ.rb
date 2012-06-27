re = gets.to_i
re.times do
    n = gets.to_i
    m = Math.sqrt(n).to_i
    m -= 1 while n % m > 0
    p n / m - m
end
