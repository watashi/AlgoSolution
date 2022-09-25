# @param {String[]} names
# @param {Integer[]} heights
# @return {String[]}
def sort_people(names, heights)
    x = heights.zip(names).sort.reverse.map{|i| i[1]}
end
