c = [0] * 5
gets
gets.split.each{|_| c[_.to_i] += 1}
if c[2].odd?
    c[2] += 1
    c[1] -= 2
end
p ([0, c[1] - c[3]].max + 3) / 4 + c[2] / 2 + c[3] + c[4]
