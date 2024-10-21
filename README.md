# Animal's Basic Language Comparisons

While the specific goals of this project have shifted and warped over time, at the end of the day it provides examples of various programs implemented in various languages.

My (current) aim is to provide a large repository of working code examples, helping developers to make an informed choice when deciding what language to use in their next project, while also showing newbies what the language they are learning looks like in action.

## Usage

The primary intended usage of this project is to compare the source code of various implementations of the same specification (i.e looking at all the "hello_world" implementations). Each specification has an "implemented in" list to aid in this.

That said, each implementation is a fully functioning program, to run a given implementation use the language's `runner.sh` script, giving it the name of the program followed by any arguments to the program. For example, here is how you would run C's "fizzbuzz" implementation with the input "30":

`./code/c/runner.sh fizzbuzz 30`

## Compatibility

As much as I would like to have this be a fully cross-platform project, at the end of the day I am a single developer working on a GNU/Linux system. For the time being at least, only GNU/Linux distributions are officially supported.

## Layout

The directory structure is as follows:

* spec/*spec* - A document detailing a given program.

* spec/template.md - A template showing how specifications should be structured.

* code/*lang* - Everything related to language *lang*.

* code/*lang*/*spec* - Implementation of specification *spec* in language *lang*

* code/*lang*/runner.sh - A shell script for (building and) running implementations.

* code/scripts/common.sh - A file containing functions used in runner.sh's.

## Contribution

Contributions welcome! See `CONTRIBUTING.md`.

## License

This project is licensed under the MIT License, see `LICENSE.md`.
