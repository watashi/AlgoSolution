# @param {String} sentence
# @return {Integer}
def count_valid_words(sentence)
    sentence.split.count do |w|
        w =~ /^[a-z]*([a-z]-[a-z]+)?[!.,]?$/
    end
end
