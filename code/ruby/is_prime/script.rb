if ARGV.empty?
  STDERR.puts "No number specified, exiting."
  exit 1
end

num = ARGV[0].to_i

if num == 0 && !ARGV[0].match('0+\.?0*')
  STDERR.puts "\"#{ARGV[0]}\" cannot be converted into a number, exiting."
  exit 1
end

if ARGV[0].match('\d+\.[1-9]+')
  puts "False"
  exit 1
end

if num <= 1 || num > 2 && num % 2 == 0 || num > 3 && num % 3 == 0
  puts "False"
  exit
end

i = 5
until i*i >= num do
  if num % i == 0 || num % (i+2) == 0
    puts "False"
    exit
  end
  i += 6
end

puts "True" 
