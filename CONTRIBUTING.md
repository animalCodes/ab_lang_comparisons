# Contribution rules

When contributing to this project, please adhere to the following rules:

* **Folder layout**: All contributions must adhere to the folder layout noted in README.md, so the "hello world" program written in C must be located in `/code/c/hello_world`, and nothing else.

* **File / Folder naming**: All folders and files should use *snake_case*. Exceptions are actual code files, which should follow the language's conventions, (Main.java, Program.cs, etc.)

## Implementations

* The main file of each implementation must have a prominent "header comment" containing the text `{lang} {specification}`. For example `C hello_world`.

* **Libraries**: This project is intended to show what it is like to code in various languages, so in general no third-party libraries or frameworks. Only the standard library should be used. Exceptions:
    * Tools that are very commonly used. (for instance Cargo with Rust) if it is likely programmers will use a tool, it should be demonstrated.
    * Where the program would be prohibitively difficult to implement otherwise, in which case libraries may be used, but please keep to a minimum.

* **Comments**: Try to keep comments to a minimum so as not to clutter source code. Additionally, comments should state *why* something is being done, not *what*.

* **Packages**: For languages that require packages, ideally use a name similar to "comparisons.{language}.{project}". For example, "comparisons.java.helloworld". Whatever format is used, ensure the relevant `runner.sh` script will be able to recognise it.

* **Impossibilities**: In the case where it is literally impossible to implement a specification in a language, a file named "no_code.md" should be written in its place which explains why it is impossible to implement.

## Specifications

* When contributing a new specification, make sure it follows the format in `/spec/template.md`, and that it can be implemented in at least *most* languages - preferably all!

* Pull requests contributing a new specification should ideally contain an implementation of that specification.

* In the case where a specification needs to be revised in such a way that current implementations no longer follow it, the "Implemented in" list should be reset, but the implementations should be kept and updated separately.

## New languages

"Adding a new language" to the project consists of the following:
  
* Create a new directory in `/code` for it,

* Add it to the "to be implemented in" list for all relevant specifications,

* Implement the hello_world specification,

* Create a `runner.sh` script, this should be as easy as copying an existing runner and updating language-specific commands.
