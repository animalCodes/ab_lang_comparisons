import sys

# Python vigenere_cipher

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

if len(sys.argv) < 2:
    print("No message given, exiting", file=sys.stderr)
    sys.exit(1)

key = input("Enter key: ").lower()

if len(key) < 1:
    print("No key given, exiting.")
    sys.exit(1)

if not key.isalpha():
    print("Key contains non-alphabetical characters, exiting.")
    sys.exit(1)

message = ' '.join(sys.argv[1:]).lower()

i = 0
k = 0

while i < len(message):
    if k >= len(key):
        k = 0

    if message[i] in alphabet:
        index = (alphabet.index(message[i]) + alphabet.index(key[k])) % 26
        print(alphabet[index], end="")
        k += 1
    else:
        print(message[i], end="")

    i += 1

print()
