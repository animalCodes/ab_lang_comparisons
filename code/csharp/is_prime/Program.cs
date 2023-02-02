// Get input
// See fizzbuzz implementation for an explanation of this oddness
string input;
if (args.Length > 1) 
{input = args[1];}
else if (args.Length > 0)
{input = args[0];}
else {
    Console.WriteLine("Unable to locate input, exiting");
    Environment.Exit(1);
    // Yes, I know that this will never run - but the compiler thinks it will.
    // (If we don't set `input` here the compiler will believe it might be null.)
    input = "";
}

// Attempt to convert to an integer
int num = 0;
if (!Int32.TryParse(input, out num))
{
    Console.WriteLine($"Unable to convert \"{input}\" to a number");
    Environment.Exit(2);
}

// Exit early if we can assume the number isn't prime.
if (num < 2) {
    Console.WriteLine("False");
    Environment.Exit(0);
}

// Figure out if prime
int divisor = num-1;
while (divisor > 1) 
{
    if (num % divisor == 0)
    {
        Console.WriteLine("False");
        Environment.Exit(0);
    }
    divisor--;
}

Console.WriteLine("True");
