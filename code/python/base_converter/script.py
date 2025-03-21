import sys, math

# Python base_converter

if len(sys.argv) < 3:
    if len(sys.argv) < 2:
        print("No base or number specified, exiting.", file=sys.stderr)
    else:
        print("No number specified, exiting.", file=sys.stderr)
    sys.exit(1)

try: n = math.floor(float(sys.argv[2]))
except ValueError:
    print(f"\"{sys.argv[2]}\" isn't a decimal integer, exiting.")
    sys.exit(1)

match sys.argv[1]:
    case "2":
        print(f"{n:b}")
    case "8":
        print(f"{n:o}")
    case "16":
        print(f"{n:X}")
    case _:
        print("Base must be 2, 8, or 16, exiting.", file=sys.stderr)
        sys.exit(1)
