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
/*
 The `out` keyword causes the argument to be passed *by reference*, essentially
 meaning the method is given *the variable itself* rather than just its value.
 What this allows us to do in this case is update the value of num while also 
 checking whether it should be, as TryParse both modifies the given `short` 
 and returns a boolean representing whether the string was converted successfully.
*/
if (!Int16.TryParse(args[0], out num))
{
    Console.Error.WriteLine($"Unable to parse \"{args[0]}\" as a number, exiting.");
    return 2;
}

// Use StringBuilder to avoid string concatenation, this is dumb over-engineering which you should avoid.
StringBuilder output = new StringBuilder(4);
if (num % 3 == 0) 
    output.Append("Fizz");
if (num % 5 == 0)
    output.Append("Buzz");

if (num == 0 || output.Length <= 0)
{
    // Replace content with num
    output.Clear();
    output.Append(num);
}

Console.WriteLine(output.ToString());

return 0;
