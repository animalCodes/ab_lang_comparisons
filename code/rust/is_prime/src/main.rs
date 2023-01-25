use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect(); 

    // Retrieve argument
    let arg = match args.get(1) {
        None => {
            eprintln!("No number specified.");
            process::exit(1);
        },
        Some(str) => str,
    };

    // Attempt to convert to number
    let num: i32 = match arg.parse() {
        Err(_) => {
            eprintln!("Unable to parse '{arg}' as a number");
            process::exit(2);
        },
        Ok(n) => n,
    };

    if num < 2 {
        println!("False");
        process::exit(0);
    }

    // Make a copy of num-1
    let mut divisor = num-1;
    // Check remainder of num / every number lesser than it.
    while divisor > 1 {
        if num % divisor == 0 {
            println!("False");
            process::exit(0);
        }
        divisor -= 1;
    }

    // If we've gotten this far without exiting, number wasn't divisible by
    // anything, so must be prime.
    println!("True");
}
