require 'prime'

a = 1.upto(100).map{|i| Prime.each(20).map{|j| (i + j - 1) / j}}
a.each{|b| p b}
