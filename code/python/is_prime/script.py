import sys, math

# Python is_prime

if len(sys.argv) < 2:
    print("No number specified, exiting.", file=sys.stderr)
    sys.exit(1)

try: n = float(sys.argv[1])
except ValueError:
    print(f'"{sys.argv[1]}" cannot be converted into a number, exiting.',
          file=sys.stderr)
    sys.exit(1)

if math.floor(n) != n:
    print("False")
    sys.exit(0)

if n < 2 or (n > 2 and n % 2 == 0) or (n > 3 and n % 3 == 0):
    print("False")
    sys.exit(0)

i = 5
while i*i <= n:
    if n % i == 0 or n % (i+2) == 0:
        print("False")
        break
    i += 6
else:
    print("True")
