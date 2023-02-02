// Only needed to access StringBuilder
using System.Text;
/* Get input
 This is a little more complicated than usual as depending on how the program 
 is run, the actual input we want may be in index '0' or '1'. 
 Basically if run with `dotnet run fizzbuzz.csproj {input}` the argument 
 will be in index '1', but if run with just `dotnet run {input}` (perfectly 
 valid if run in the directory of the .csproj file) the argument will be at 
 index '0'.
 Due to the runner.sh script, this shouldn't actually be a problem, but it's 
 always good to account for known edge cases.
*/
string arg = "";
// If args has more than 1 value, assume number is at index 1.
if (args.Length > 1 )
{arg = args[1];} 
// If args has 1 value, assume that value is the number.
else if (args.Length == 1) 
{arg = args[0];}
// Otherwise, no arguments have been specified.
else {
    // Environment and Console are both in the System namespace, which top-level
    // statements are implicity wrapped in.
    Console.WriteLine("Unable to find argument, exiting.");
    return 1;
}

// Convert to number
Int16 num = 0;
/*
 The `out` keyword causes the argument to be *passed by reference*, essentially
 meaning the method is given *the variable itself* rather than just it's value.
 What this allows us to do in this case is update the value of num while also 
 checking whether it should be, as TryParse both modifies the given `short` 
*/
// *and* returns a boolean representing whether the string was converted successfully.
if (!Int16.TryParse(arg, out num))
{
    Console.WriteLine($"Unable to parse \"{arg}\" as a number, exiting.");
    return 2;
}

// Do FizzBuzzing
// It would be perfectly possible to use a `string` and `+=` but doing so creates
// a new string in memory every time, so use a StringBuilder to save on memory 
// allocation.
StringBuilder output = new StringBuilder(4);
if (num % 3 == 0) 
{output.Append("Fizz");}
if (num % 5 == 0)
{output.Append("Buzz");}

if (num == 0 || output.Length <= 0)
{
    // Replace content with num
    output.Clear();
    output.Append(num);
}

Console.WriteLine(output.ToString());
return 0;
