# Contribution rules

When contributing to this project, please adhere to the following rules:

* **Folder layout**: Applications must be contained within their own folders, so the "hello world" program written in C must be located in `/code/c/hello_world`, and nothing else.

* **File / Folder naming**: All folders and files should use *snake_case*. Exceptions are actual code files, which should follow the language's conventions, (Main.java, Program.cs, etc.)

* **Entry points**: All languages have a `runner.sh` file which simplifies running the code, to ensure these work make sure that the file containing the entry point of each implementation is named according to the below mapping:

* C: `main.c`
* C++: `main.cpp`
* C#: `Program.cs`
* denoJS/Node.js: `app.js`
* Go: `main.go`
* Java: `Main.java`
* Kotlin: `Main.kt`
* Ruby: `script.rb`
* Rust: `main.rs`
* Other: `main.(extension)`

* **Libraries**: This project is intended to show what it is like to code in various languages, so in general no third-party libraries or frameworks. Only the standard library should be used. Exceptions:
    * Tools that are very commonly used. (for instance Cargo with Rust) if it is likely programmers will use a tool, it should be demonstrated.
    * Where the program would be prohibitively difficult to implement otherwise, in which case libraries may be used, but please keep to a minimum.

* **Comments**: In general, comments should be avoided where possible to avoid clutter. The exception to this is when an implementation uses an unusual feature or otherwise where the code is unclear, in which case a note should be added explaining what is going on.

* **Packages**: For languages that require packages, ideally use a name similar to "comparisons.{language}.{project}". E.G. "comparisons.java.helloworld", but if something else would fit better with the language, please use that instead.

* **Impossibilities**: In the case where it is literally impossible to implement a demo in a language, a file named "no_code.md" should be written in its place which explains why it is impossible to implement.

## Specifications

* When contributing a new spec, make sure it follows the format in `/spec/template.md`, and that it can be implemented in atleast *most* languages - preferably all!

* In the case where a specification needs to be revised in such a way that current implementations no longer follow it, the "Implemented in" list should be wiped, but the implementations should be kept and updated separately.

## New languages

"Adding a new language" to the project consists of the following:
  
* Create a new directory in `/code` for it,

* Add it to the "to be implemented in" list for all relevant specifications,

* Implement the hello_world specification,

* Create a `runner.sh` file, this should be as easy as copying an existing runner and updating language-specific commands.

Before adding a new language, make sure it can implement the majority of the specifications, it's okay if a couple aren't possible. (Just make sure to add no_code.md files)
