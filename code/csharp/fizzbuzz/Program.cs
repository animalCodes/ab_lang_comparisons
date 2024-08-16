if (args.Length < 1)
{
    Console.Error.WriteLine("No number specified, exiting.");
    return 1;
}

Int16 num = 0;
if (!Int16.TryParse(args[0], out num))
{
    Console.Error.WriteLine(
        $"{args[0]} cannot be converted into a number, exiting.");
    return 1;
}

string output = "";
if (num % 3 == 0)
    output += "Fizz";
if (num % 5 == 0)
    output += "Buzz";

if (num == 0 || output.Length <= 0)
    output = $"{num}";

Console.WriteLine(output);

return 0;
