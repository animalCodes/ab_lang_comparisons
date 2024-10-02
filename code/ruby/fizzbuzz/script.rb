
# Ruby fizzbuzz

if (ARGV.empty?) then
  STDERR.puts "No number specified, exiting."
  exit
elsif !ARGV[0].start_with?(/\d+/) then
  STDERR.puts "\"#{ARGV[0]}\" cannot be converted into a number, exiting."
  exit
end

num = ARGV[0].to_f

str = ""
str += "Fizz" if num % 3 == 0
str += "Buzz" if num % 5 == 0

if str == "" || num == 0 then
  # Don't print any decimal places
  puts num.to_i
else
  puts str
end
