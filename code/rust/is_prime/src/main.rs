use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect(); 

    let arg = match args.get(1) {
        None => {
            eprintln!("No number specified.");
            process::exit(1);
        },
        Some(str) => str,
    };

    let num = match arg.parse::<i32>() {
        Err(_) => {
            eprintln!("Unable to parse '{arg}' as a number");
            process::exit(2);
        },
        Ok(n) => n,
    };

    // If any of these checks pass, the number can't be prime.
    if num < 2
        || num > 2 && num % 2 == 0 
        || num > 3 && num % 3 == 0 {
        println!("False");
        process::exit(0);
    }

    // Trial Division
    let mut divisor = 5;
    while divisor*divisor <= num {
        if num % divisor == 0 || num % (divisor+2) == 0 {
            println!("False");
            process::exit(0);
        }
        divisor += 6;
    }

    // If we've gotten this far without exiting, number wasn't divisible by
    // anything, so must be prime.
    println!("True");
}
