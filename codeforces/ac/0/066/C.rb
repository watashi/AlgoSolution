def gao(dir)
	if dir.empty?
		return 0, 1
	else
		fold, file = 1, 0
		dir.each do |_, subdir|
			foldx, filex = gao(subdir)
			fold += foldx
			file += filex
		end
		return fold, file
	end
end

dir = {}
readlines.each do |line|
	pwd = dir
	line.split(?\\).each do |path|
		pwd[path] = {} unless pwd.has_key? path
		pwd = pwd[path]
	end
end

fold, file = 0, 0
dir.each do |_, drive|
	drive.each do |_, dirx|
		foldx, filex = gao(dirx)
		fold = [fold, foldx].max
		file = [file, filex].max
	end
end

puts "#{fold - 1} #{file}"
