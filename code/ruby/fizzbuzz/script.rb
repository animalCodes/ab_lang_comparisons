# Check user has specified an argument
if (ARGV.empty?) then
  puts "No number specified, exiting."
  exit
  # Crude check for if argument can be converted to a number - starts with atleast one digit.
elsif !ARGV[0].start_with?(/\d+/) then
  puts "Unable to convert #{ARGV[0]} to a number."
  exit
end
# Get input, Convert to int
num = ARGV[0].to_i

# So with ruby you can put if statements after the code you want to run if the condition passes.. Idk
str = ""
str += "Fizz" if num % 3 == 0
str += "Buzz" if num % 5 == 0

# Override if num is 0, as the remainder of e.g. 0 / 5 will be 0.
if str == "" || num == 0 then puts num
else puts str end
