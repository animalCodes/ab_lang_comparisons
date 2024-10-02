use std::env;
use std::process;

// Rust fizzbuzz

fn main() {
    let args: Vec<String> = env::args().collect();

    let arg = match args.get(1) {
        None => {
            eprintln!("No number specified, exiting.");
            process::exit(1);
        },
        Some(str) => str,
    };

    let val = match arg.parse::<f32>() {
        Err(_) => {
            eprintln!("\"{arg}\" cannot be converted into a number, exiting.");
            process::exit(1);
        },
        Ok(n) => n,
    };

    if val.floor() != val {
        println!("{val}");
        process::exit(1);
    }

    let num = val as i32;

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
