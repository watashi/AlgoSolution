# @param {String} sentence
# @param {Integer} discount
# @return {String}
def discount_prices(sentence, discount)
    f = (100 - discount) / 100.0
    ws = sentence.split.map do |i|
        if i =~ /^\$(\d+)$/
            '$%.2f' % [$1.to_i * f]
        else
            i
        end
    end * ' '
end
