# @param {String[]} words
# @param {Integer} left
# @param {Integer} right
# @return {Integer}
def vowel_strings(words, left, right)
    words[left..right].count{|i| 'aeiou'.include?(i[0]) && 'aeiou'.include?(i[-1])}
end
