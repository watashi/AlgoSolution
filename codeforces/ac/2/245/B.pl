#!perl -pl
s|tp(.+)ru|"tp://$1.ru".($'?"/":"")|e
