use std::env;
use std::process;

fn main() {
    // Get all arguments given to program.
    let args: Vec<String> = env::args().collect(); 

    // Use the second argument as the first is usually just a path to the program.
    let arg = match args.get(1) {
        // `.get()` returns an instance of `Option<T>`, an enum which can be either `None` or
        // `Some<T>`, this checks which it is and either exits the program or returns the value
        // from `Some<T>`.
        None => {
            // Bit cleaner then panicking
            eprintln!("No number specified.");
            process::exit(1);
        },
        // Rust doesn't really use `return` statements, instead you just kinda plop the resulting
        // expression down. /shrug
        Some(str) => str,
    };

    // Convert to number
    let num: i32 = match arg.parse() {
        // Same idea as above but this time a `Result<T, E>` Which can be either `Err(E)`
        // if an error occurred or `Ok(T)` if all good.
        Err(_) => {
            eprintln!("Unable to parse '{arg}' as a number");
            process::exit(2);
        },
        Ok(n) => n,
    };
    
    // Figure out what to print
    let mut str = String::new();

    if num % 3 == 0 {str.push_str("Fizz");}

    if num % 5 == 0 {str.push_str("Buzz");}

    // Use `String::from` rather than just `str = arg` as arg is actually a `&String`. Meaning it's
    // essentially a reference to a String in memory instead of an actual string.
    if str.is_empty() || num == 0 {str = String::from(arg)};

    // And print it.
    println!("{str}");
}
