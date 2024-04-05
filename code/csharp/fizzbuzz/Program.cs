// Only needed to access StringBuilder
using System.Text;

if (args.Length < 1)
{
    // Console is in the System namespace, which top-level
    // statements are implicity wrapped in.
    Console.Error.WriteLine("Unable to find argument, exiting.");
    return 1;
}

Int16 num = 0;
if (!Int16.TryParse(args[0], out num))
{
    Console.Error.WriteLine($"Unable to parse \"{args[0]}\" as a number, exiting.");
    return 2;
}

// Use StringBuilder to avoid string concatenation, this is dumb over-engineering which you should avoid.
// TODO this is dumb, use string concatenation
StringBuilder output = new StringBuilder(4);
if (num % 3 == 0) 
    output.Append("Fizz");
if (num % 5 == 0)
    output.Append("Buzz");

if (num == 0 || output.Length <= 0)
{
    output.Clear();
    output.Append(num);
}

Console.WriteLine(output.ToString());

return 0;
