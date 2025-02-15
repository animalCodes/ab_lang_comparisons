import sys, math

# Python fib

def fib(n):
    if (n <= 1):
        return n
    return fib(n-1) + fib(n-2)

n = 0

if (len(sys.argv) > 1):
    try: n = math.floor(float(sys.argv[1]))
    except ValueError: pass

print(fib(n))
