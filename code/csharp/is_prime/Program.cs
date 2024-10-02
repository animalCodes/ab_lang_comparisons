
// C# is_prime

if (args.Length < 1)
{
    Console.Error.WriteLine("No number specified, exiting");
    return 1;
}

double num = 0;
if (!Double.TryParse(args[0], out num))
{
    Console.Error.WriteLine(
        $"\"{args[0]}\" cannot be converted into a number, exiting.");
    return 2;
}

if (Double.Floor(num) != num) {
    Console.WriteLine("False");
    return 0;
}

if (num < 2 || num % 2 == 0 && num != 2
    || num % 3 == 0 && num != 3)
{
    Console.WriteLine("False");
    return 0;
}

int divisor = 5;
while (divisor*divisor <= num)
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
