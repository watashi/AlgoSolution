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

begin
  require 'wirble'
  def pp(status)
    puts Wirble::Colorize.colorize(status.inspect)
  end
rescue LoadError
  alias :pp :p
end

def usage
  print <<-USAGE
Usage:
  rosalind.rb login
  rosalind.rb $pid.pl dl
  rosalind.rb $pid.pl up
USAGE
  exit 1
end

$pl, $op = *$*

if $pl =~ /login/i
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
    status = $rosalind.judge! id, [output, 'output'], [source, $pl]
    pp status
    if status && status[:status] == 'Correct'
      FileUtils.mv $pl, 'pl/', :verbose => true
      FileUtils.mv "rosalind_#{id}.txt", 'txt/', :verbose => true
      FileUtils.rm "rosalind_#{id}.txt.index", :force => true
    end
  else
    usage
  end
else
  usage
end

