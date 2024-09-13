use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();

    let arg = match args.get(1) {
        None => {
            eprintln!("No number specified, exiting.");
            process::exit(1);
        },
        Some(str) => str,
    };

    let num = match arg.parse::<i32>() {
        Err(_) => {
            eprintln!("{arg} cannot be converted into a number, exiting.");
            process::exit(1);
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

    if out.is_empty() || num == 0 {
        out = String::from(arg)
    }

    println!("{out}");
}
