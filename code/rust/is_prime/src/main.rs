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

    let num = match arg.parse::<f32>() {
        Err(_) => {
            eprintln!("\"{arg}\" cannot be converted into a number, exiting.");
            process::exit(1);
        },
        Ok(n) => n,
    };

    if num.fract() > 0.0 {
        println!("False");
        process::exit(0);
    }

    if num < 2.0
        || num > 2.0 && num % 2.0 == 0.0
        || num > 3.0 && num % 3.0 == 0.0 {
        println!("False");
        process::exit(0);
    }

    let mut divisor = 5.0;
    while divisor*divisor <= num {
        if num % divisor == 0.0 || num % (divisor+2.0) == 0.0 {
            println!("False");
            process::exit(0);
        }
        divisor += 6.0;
    }

    println!("True");
}
