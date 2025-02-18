import sys

# Python caesar_cipher

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

if len(sys.argv) < 3:
    if len(sys.argv) < 2:
        print("No shift or message given, exiting.", file=sys.stderr)
    else:
        print("No message given, exiting.")
    sys.exit(1)

try: shift = int(sys.argv[1])
except ValueError:
    print(f"Couldn't convert \"{sys.argv[1]}\" to an integer, exiting.",
          file=sys.stderr)
    sys.exit(1)

message = ' '.join(sys.argv[2:]).lower()

for c in message:
    if not c in alphabet:
        print(c, end='')
        continue

    i = (alphabet.index(c) + shift) % 26
    if i < 0:
        i += 26

    print(alphabet[i], end='')

print()

