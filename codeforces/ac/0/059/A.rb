gets
u = $_.scan(/[A-Z]/).size
l = $_.scan(/[a-z]/).size
puts u > l ? $_.upcase : $_.downcase
