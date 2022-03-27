# @param {Integer[]} queries
# @param {Integer} int_length
# @return {Integer[]}
def kth_palindrome(queries, int_length)
    d = 10 ** (int_length.pred / 2)
    r = int_length / 2
    queries.map do |i|
        if i > 9 * d
            -1
        else
            hi = (d + i - 1)
            lo = hi.to_s[0...r].reverse.to_i(10)
            hi * 10 ** r + lo
        end
    end
end
