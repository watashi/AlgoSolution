#!/usr/bin/ruby

BEGIN {
  require 'ojagent'

  $filename = 'rosalind.cookie'
  $rosalind = OJAgent::RosalindAgent.new
  $rosalind.agent.cookie_jar.load $filename if File.readable? $filename
}

END {
  $rosalind.agent.cookie_jar.save_as $filename
  FileUtils.chmod 0600, $filename
}

require 'highline'

$op, $pl = *$*

if $op =~ /login/i
  hl = HighLine.new
  user = hl.ask("Username: ")
  pass = hl.ask("Password: "){|q| q.echo = false}
  $rosalind.login user, pass
elsif $pl =~ /[a-z]*/
  id = $&
  if $op =~ /dl|download|open/i
    input = $rosalind.open! id
    IO.write input.filename, input.content
    system %{perl #{$pl} #{input.filename} | tee output}
  elsif $op =~ /up|upload|submit/i
    output = IO.read('output')
    source = IO.read($pl)
    p $rosalind.judge! id, [output, 'output'], [source, $pl]
  elsif $op =~ /ac|archive/i
    FileUtils.mv $pl, 'pl/', :verbose => true
    FileUtils.mv "rosalind_#{id}.txt", 'txt/', :verbose => true
    FileUtils.rm "rosalind_#{id}.txt.index", :force => true
  end
end

