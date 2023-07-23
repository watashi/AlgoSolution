# @param {String[]} words
# @param {Character} separator
# @return {String[]}
def split_words_by_separator(words, separator)
    words.map{|i| i.split(separator).select{|j| !j.empty?}}.flatten
end
