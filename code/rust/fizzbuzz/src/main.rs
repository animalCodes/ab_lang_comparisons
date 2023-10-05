use std::env;
use std::process;

fn main() {
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

    let num = match arg.parse::<i32>() {
        // Same idea as above but this time a `Result<T, E>` Which can be either `Err(E)`
        // if an error occurred or `Ok(T)` if all good.
        Err(_) => {
            eprintln!("Unable to parse '{arg}' as a number");
            process::exit(2);
        },
        Ok(n) => n,
    };
    
    let mut out = String::new();

    if num % 3 == 0 {
        out.push_str("Fizz");
    }
    if num % 5 == 0 {
        out.push_str("Buzz");
    }

    // Use `String::from` rather than just `str = arg` as arg is actually a `&String`. Meaning it's
    // essentially a reference to a String instead of an actual String.
    if out.is_empty() || num == 0 {
        out = String::from(arg)
    }

    println!("{out}");
}
