# Get input, check if it's valid.
if ARGV.empty?
  puts "No number specified."
  exit
# String#to_i returns 0 if unable to convert self to a number
elsif ARGV[0].to_i == 0 && ARGV[0] != "0"
  puts "Unable to convert \"#{ARGV[0]}\" to a number."
  exit
end

num = ARGV[0].to_i

# If num is less than 2, greater than 2 and divisible by 2, or greater than 3 and divisible by 3..
if num <= 1 || num > 2 && num % 2 == 0 || num > 3 && num % 3 == 0
  puts "False"
  exit
end

i = 5
# Loop `until` i is or is greater than the square root of num
until i*i >= num do
  if num % i == 0 || num % (i+2) == 0
    puts "False"
    exit
  end
  i += 6
end

puts "True" 
