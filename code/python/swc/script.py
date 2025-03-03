import sys, argparse

# Python swc

help_message = """\
Usage: swc [options] file
Print newline, word and byte counts for file. A word is a sequence of
non-whitespace delimited by whitespace or start/end of input.

The options below may be used to select which counts are printed, always in the
following order: newline, word, byte.
  -c  print byte count.
  -l  print newline count.
  -w  print word count.
  -h  display this help and exit.
"""

def words(line):
    """Number of words in `line`."""
    count = 0
    space = True
    for char in line:
        if char.isspace():
            space = True
        elif space:
            count += 1
            space = False
    return count

parser = argparse.ArgumentParser(add_help=False, exit_on_error=False)
parser.add_argument("-c", action="store_true", dest="bytes")
parser.add_argument("-l", action="store_true", dest="lines")
parser.add_argument("-w", action="store_true", dest="words")
parser.add_argument("-h", action="store_true", dest="help")
parser.add_argument("files", nargs="*")

args, unknown = parser.parse_known_args()

if len(args.files) == 0:
    print("No file specified, exiting.", file=sys.stderr)
    sys.exit(1)

if args.help:
    print(help_message)
    sys.exit(0)

if len(unknown) > 0:
    print(f'Invalid option "{unknown[0].strip("-")}", try "swc -h for help.',
        file=sys.stderr)
    sys.exit(1)

byte_count = 0
line_count = 0
word_count = 0

try:
    with open(args.files[0], 'r', encoding="utf-8") as file:
        for line in file:
            line_count += 1
            word_count += words(line)
            byte_count += len(line)
except (FileNotFoundError, PermissionError):
    print(f'Cannot access file "{path}"', file=sys.stderr)
    sys.exit(1)

if not args.lines and not args.words and not args.bytes:
    args.lines = True
    args.words = True
    args.bytes = True

if args.lines:
    print(line_count, end="")
    if args.words or args.bytes:
        print(" ", end="")
if args.words:
    print(word_count, end="")
    if args.bytes:
        print(" ", end="")
if args.bytes:
    print(byte_count, end="")

print()
