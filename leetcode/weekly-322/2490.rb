# @param {String} sentence
# @return {Boolean}
def is_circular_sentence(sentence)
    w = sentence.split
    w[0][0] == w[-1][-1] && w.each_cons(2).all?{|i, j| i[-1] == j[0]}
end
