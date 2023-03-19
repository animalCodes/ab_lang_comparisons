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
if (num < 2
        // A number can't be divided by a number greater than itself, so in this case `!= 2` and `!= 3` are equivalent to `> 2` and `> 3`.
    || num % 2 == 0 && num != 2
    || num % 3 == 0 && num != 3) {
    Console.WriteLine("False");
    return 0;
}

// Figure out if prime
int divisor = 5;
while (divisor*divisor < num) 
{
    if (num % divisor == 0 || num % (divisor + 2) == 0)
    {
        Console.WriteLine("False");
        return 0;
    }
    divisor += 6;
}

Console.WriteLine("True");
return 0;
