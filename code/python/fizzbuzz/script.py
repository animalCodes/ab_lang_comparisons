import sys, math

# Python fizzbuzz

if len(sys.argv) < 2:
    print("No number specified, exiting.", file=sys.stderr)
    sys.exit(1)

try: n = float(sys.argv[1])
except ValueError:
    print(f'"{sys.argv[1]}" cannot be converted into a number, exiting.',
          file=sys.stderr)
    sys.exit(1)

if n % 3 == 0 and n % 5 == 0:
    print("FizzBuzz")
elif n % 3 == 0:
    print("Fizz")
elif n % 5 == 0:
    print("Buzz")
else:
    print(sys.argv[1])
