if ARGV.empty?
  STDERR.puts "No number specified."
  exit
elsif ARGV[0].to_i == 0 && ARGV[0] != "0"
  STDERR.puts "Unable to convert \"#{ARGV[0]}\" to a number."
  exit
end

num = ARGV[0].to_i

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
