# Get input, check if it's valid.
if ARGV.empty?
  puts "No number specified."
  exit
# String#to_i returns 0 if unable to convert self to a number
elsif ARGV[0].to_i == 0 && ARGV[0] != "0"
  puts "Unable to convert #{ARGV[0]} to a number."
  exit
end

num = ARGV[0].to_i

# num being <= 1 will skip the loop and make the program 'think' the number is prime, which is incorrect.
if num <= 1
  puts "False"
  exit
end

i = num-1
# Loop `until` i is at most 1
until i <= 1 do
  if num % i == 0
    puts "False"
    exit
  end
  i -= 1
end

puts "True"
