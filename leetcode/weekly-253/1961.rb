# @param {String} s
# @param {String[]} words
# @return {Boolean}
def is_prefix_string(s, words)
    words.each do |i|
        if s.start_with?(i)
            s = s.delete_prefix(i)
        else
            break
        end
    end
    s.size == 0
end
