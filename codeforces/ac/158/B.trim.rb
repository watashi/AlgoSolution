c=[0]*5
gets
gets.split.each{|_|c[_.to_i]+=1}
p ([0,c[1]-c[3]].max+2*c[2]+3)/4+c[3]+c[4]
