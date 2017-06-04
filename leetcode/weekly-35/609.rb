# @param {String[]} paths
# @return {String[][]}
def find_duplicate(paths)
    m = {}
    paths.each do |path|
        dir, *files = *path.split(' ')
        files.each do |file|
            if (file =~ /^(.*)\((.*)\)$/)
                m[$2] = [] unless m.has_key? $2
                m[$2] << dir + '/' + $1
            end
        end
    end
    # p m
    m.values.select{|i| i.size > 1}
end
