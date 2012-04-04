class Box
	attr_accessor :border, :spacing
	
	def initialize(type, width, height)
		@type = type
		@border = 0
		@spacing = 0
		@repaint = false
		@width = width
		@height = height
		@element = []
	end

	def repaint
		@repaint = true
		return if @type == 'W'
		@height = @width = 0
		if @element.size > 0
			if @type == 'V'
				@element.each do |e|
					@height += e.height
					@width = [@width, e.width].max
				end
				@height += 2 * border + (@element.size - 1) * spacing
				@width += 2 * border
			elsif @type == 'H'
				@element.each do |e|
					@height = [@height, e.height].max
					@width += e.width
				end
				@height += 2 * border
				@width += 2 * border + (@element.size - 1) * spacing
			end
		end
	end

	def height
		repaint unless @repaint
		@height
	end

	def width
		repaint unless @repaint
		@width
	end

	def pack(w)
		@element << w
	end
end

w = {}

gets.to_i.times do
	$_ = gets.chomp
	if /Widget (\w+)\((\d+),(\d+)\)/
		w[$1] = Box.new('W', $2.to_i, $3.to_i)
	elsif /(V|H)Box (\w+)/
		w[$2] = Box.new($1, 0, 0)
	elsif /(\w+)\.set_border\((\d+)\)/
		w[$1].border = $2.to_i
	elsif /(\w+)\.set_spacing\((\d+)\)/
		w[$1].spacing = $2.to_i
	elsif /(\w+)\.pack\((\w+)\)/
		w[$1].pack(w[$2])
	else
		puts "ERROR: $_\n"
	end
end

w.keys.sort.each do |k|
	puts "#{k} #{w[k].width} #{w[k].height}"
end
