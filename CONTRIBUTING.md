# Contribution rules

The aim of this project is to accurately demonstrate what it is like to use different programming languages, to ensure this please adhere to the following rules:

* Applications must be contained within their own folders, so the "hello world" program written in C must be located in `/code/c/hello_world`, and nothing else.

* File / Folder naming: All folders and files should use *snake_case*. Exceptions are actual code files, which should follow the languages' conventions, (Main.java, Program.cs, etc.)

* Entry points: All languages have a `runner.sh` file which simplifies running the code, to ensure these work make sure the entry point of each implementation is named according to the below mapping:

* C: `main.c`
* C++: `main.cpp`
* C#: `Program.cs`
* denoJS/Node.js: `app.js`
* Java: `Main.java`
* Kotlin: `Main.kt`
* Ruby: `script.rb`
* Rust: `main.rs`
* Other: `main.(extension)`

* **No libraries**! This project is purely to show what it is like to code in various languages, so no third-party libraries or frameworks. Only the standard library may be used, if that makes the program hard to implement, then the project is working as intended.

* Commonly used tools: An exception/caveat to the above rule is tools that are very commonly used. (for instance Maven with Java) Again, this project is to showcase what it is like to use different languages, so if it is likely programmers will use a tool. It should be demonstrated.

* Comments: One use of this project is to help new users of a language get an idea of what using it is like, so when documenting your code try to imagine someone who doesn't really understand the language is reading it. If the language has an odd/unusual feature (*cough* ruby unless statement *cough*), explain it!

* Packages: For languages that require packages, ideally use a name similar to "comparisons.{language}.{project}". E.G. "comparisons.java.helloworld", but if something else would fit better with the language, please use that instead.

* Impossibilities: In the case where it is literally impossible to implement a demo in a language, a file named "no_code.md" should be written in it's place which explains why it is impossible to implement.

## New demonstrations / specifications:

* When contributing a new spec, make sure it follows the format in /spec/template.md, and that it can be implemented in *most* languages.

* Additionally, new specifications must showcase some functionality / language features previously not seen. (For instance there is no point in a "Arch is the best" program, as it's functionality is already shown in hello world)

## New languages:

* "Adding a new language" to the project consists of the following:
  
  * Create a new directory in /code for it

  * Add it to the "to be implemented in" list for all relevent specifications

  * Implement the hello_world specification

  * Create a `runner.sh` file, this should be as easy as copying an existing runner and updating language-specific commands.

* Before adding a new language, make sure it can implement the majority of the specifications, it's okay if a couple aren't possible. (Just make sure to add no_code.md files)
