if (ARGV.empty?) then
  STDERR.puts "No number specified, exiting."
  exit
  # Crude check for if argument can be converted to a number - starts with atleast one digit.
elsif !ARGV[0].start_with?(/\d+/) then
  STDERR.puts "Unable to convert #{ARGV[0]} to a number."
  exit
end

num = ARGV[0].to_i

str = ""
# Welcome to Ruby, leave your sanity at the door.
str += "Fizz" if num % 3 == 0
str += "Buzz" if num % 5 == 0

# Override if num is 0, as the remainder of, for instance, 0 / 5 will be 0.
if str == "" || num == 0 then puts num
else puts str end
