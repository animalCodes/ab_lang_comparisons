// Get input
// See fizzbuzz implementation for an explanation of this oddness
string input;
if (args.Length > 1) 
{input = args[1];}
else if (args.Length > 0)
{input = args[0];}
else {
    Console.WriteLine("Unable to locate input, exiting");
    return 1;
}

// Attempt to convert to an integer
int num = 0;
if (!Int32.TryParse(input, out num))
{
    Console.WriteLine($"Unable to convert \"{input}\" to a number");
    return 2;
}

// Exit early if we can assume the number isn't prime.
if (num < 2) {
    Console.WriteLine("False");
    return 0;
}

// Figure out if prime
int divisor = num-1;
while (divisor > 1) 
{
    if (num % divisor == 0)
    {
        Console.WriteLine("False");
        return 0;
    }
    divisor--;
}

Console.WriteLine("True");
// Return here or the compiler will fucking die
return 0;
