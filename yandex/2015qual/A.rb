#!/usr/bin/ruby

query = gets.split
gets
dict = gets.split
puts query.all?{|i| dict.include? i} ? 'Correct' : 'Misspell'
