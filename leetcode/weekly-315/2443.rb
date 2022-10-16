# @param {Integer} num
# @return {Boolean}
def sum_of_number_and_reverse(num)
    # Time Limit Exceeded
    # 0.upto(num).any?{|i| i + i.to_s.reverse.to_i(10) == num}
    def ok?(n, d, first = false)
        p [n, d]
        if n < 0 || d < 0
            false
        elsif d == 0
            n == 0
        elsif d == 1
            n % 2 == 0 && n / 2 < 10
        else
            r = n % 10
            [r, 10 + r].any? do |i|
                (!first || i > 0) && i < 19 && ok?((n - i * (10 ** (d - 1) + 1)) / 10, d - 2)
            end
        end
    end
    d = num.to_s.size
    ok?(num, d, true) || ok?(num, d - 1, true)
end
