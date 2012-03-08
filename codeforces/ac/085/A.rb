n = gets.to_i
t = (n / 2).times.map{|i| i.odd? ? '00' : '11'} * ''
if n.odd?
	s = [
		'i' + t.tr('01', 'ab'),
		'i' + t.tr('01', 'cd'),
		t.tr('01', 'ef') + 'j',
		t.tr('01', 'gh') + 'j']
else
	s = [
		t.tr('01', 'ab'),
		t.tr('01', 'cd'),
		'i' + t[2..-1].tr('01', 'ef') + 'j',
		'i' + t[2..-1].tr('01', 'gh') + 'j']
end
puts s * "\n"
