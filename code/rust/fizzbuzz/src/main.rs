use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect(); 

    let arg = match args.get(1) {
        None => {
            // Bit cleaner then panicking
            eprintln!("No number specified.");
            process::exit(1);
        },
        // As str is the last expression here, it'll become the 
        // expression of the whole match statement
        Some(str) => str,
    };

    let num = match arg.parse::<i32>() {
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

    // Use `String::from` rather than just `str = arg` as arg is a `&String`.
    if out.is_empty() || num == 0 {
        // TODO dereference?
        out = String::from(arg)
    }

    println!("{out}");
}
