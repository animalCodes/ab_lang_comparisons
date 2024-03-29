if (args.Length < 1) 
{
    Console.Error.WriteLine("Unable to locate input, exiting");
    return 1;
}

int num = 0;
if (!Int32.TryParse(args[0], out num))
{
    Console.Error.WriteLine($"Unable to convert \"{args[0]}\" to a number");
    return 2;
}

if (num < 2
    // A number can't be divided by a number greater than itself, so in this case `!= 2` and `!= 3` are equivalent to `> 2` and `> 3`.
    // TODO what?
    || num % 2 == 0 && num != 2
    || num % 3 == 0 && num != 3) {
    Console.WriteLine("False");
    return 0;
}

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
