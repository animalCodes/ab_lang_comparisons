import sys, math

# Python sqrt

if len(sys.argv) < 2:
    square = float("nan")
else:
    try: square = float(sys.argv[1])
    except ValueError: square = float("nan")

if math.isnan(square) or square < 0:
    print("NaN")
    sys.exit(0)

if square == 0:
    print(f"{square:.5f}")
    sys.exit(0)

guess = 1

while True:
    prev = math.floor(guess)
    guess = (guess + (square / guess)) / 2
    if prev == math.floor(guess):
        break

guess = (guess + (square / guess)) / 2
guess = (guess + (square / guess)) / 2

print(f"{guess:.5f}")
