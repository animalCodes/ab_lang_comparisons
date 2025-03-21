using System;

// C# caesar_cipher

public class Program
{
    private static char[] alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z'};

    public static int Main(string[] args)
    {
        if (args.Length < 3)
        {
            if (args.Length < 2)
                Console.Error.WriteLine("No shift or message given, exiting.");
            else
                Console.Error.WriteLine("No message given, exiting.");
            return 1;
        }

        int shift = 0;
        if (!int.TryParse(args[1], out shift))
        {
            Console.Error.WriteLine($"\"{args[1]}\" isn't an integer," +
                " exiting.");
            return 1;
        }

        string message = string.Join(" ", args, 2, args.Length-2).ToLower();

        Console.WriteLine(encipher(message, shift));

        return 0;
    }

    private static string encipher(string message, int key)
    {
        char[] messageChars = message.ToCharArray();

        for (int i = 0; i < messageChars.Length; i++)
        {
            messageChars[i] = shiftChar(messageChars[i], key);
        }

        return new string(messageChars);
    }

    private static char shiftChar(char c, int key)
    {
        int charIndex = Array.IndexOf(alphabet, c);
        if (charIndex == -1)
            return c;

        charIndex += key;

        charIndex %= alphabet.Length;
        if (charIndex < 0)
            charIndex += alphabet.Length;

        return alphabet[charIndex];
    }
}
