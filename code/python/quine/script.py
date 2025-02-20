# Python quine

lines = ['# Python quine', '', '', '', 'for i in range(len(lines)):', '    if i == 2:', '        print(f"lines = {lines}")', '    else:', '        print(lines[i])']

for i in range(len(lines)):
    if i == 2:
        print(f"lines = {lines}")
    else:
        print(lines[i])
