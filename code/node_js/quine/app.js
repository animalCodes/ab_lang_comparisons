// Node.js quine

let lines = [
  '// Node.js quine',
  '',
  'let lines = %s',
  '',
  'for (let i = 0; i < lines.length; i++) {',
  '  if (i == 2)',
  '    console.log(lines[i], lines)',
  '  else',
  '    console.log(lines[i])',
  '}'
]

for (let i = 0; i < lines.length; i++) {
  if (i == 2)
    console.log(lines[i], lines)
  else
    console.log(lines[i])
}
