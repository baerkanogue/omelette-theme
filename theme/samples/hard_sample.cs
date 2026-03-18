// -*- mode: csharp; -*-

/**************************************************
 * USING / NAMESPACE
 **************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;

// File-scoped namespace (C# 10)
namespace StressTest;

// --------------------------------------------------
// PREPROCESSOR
// --------------------------------------------------

#define DEBUG

#if DEBUG
#warning "Debug mode"
#else
#error "Release required"
#endif

#region REGION_TEST
#endregion

#line 200 "fake.cs"

// --------------------------------------------------
// ATTRIBUTES
// --------------------------------------------------

[Obsolete("Use NewClass instead")]
[Serializable]
class OldClass { }

[AttributeUsage(AttributeTargets.All)]
class CustomAttr : Attribute {
    public CustomAttr(string name) { }
}

// --------------------------------------------------
// RECORDS / STRUCTS / CLASSES
// --------------------------------------------------

public record Person(string Name, int Age);

public readonly struct Point(int X, int Y);

public class Base {
    public virtual void Foo() => Console.WriteLine("Base");
}

public class Derived : Base {
    public override void Foo() => Console.WriteLine("Derived");
}

// --------------------------------------------------
// GENERICS / CONSTRAINTS
// --------------------------------------------------

class Generic<T> where T : class, new() {
    public T Create() => new T();
}

class MultiConstraint<T, U>
    where T : struct
    where U : unmanaged
{ }

// --------------------------------------------------
// ENUM
// --------------------------------------------------

enum Color : byte {
    Red = 1,
    Green,
    Blue = 10
}

// --------------------------------------------------
// PROPERTIES / INDEXERS
// --------------------------------------------------

class Props {
    public int Value { get; init; }

    private int[] data = new int[10];

    public int this[int i] {
        get => data[i];
        set => data[i] = value;
    }
}

// --------------------------------------------------
// METHODS / EXPRESSIONS
// --------------------------------------------------

class Methods {
    public static int Add(int a, int b) => a + b;

    public static void Deconstruct(out int a, out int b) {
        a = 1; b = 2;
    }
}

// --------------------------------------------------
// PATTERN MATCHING
// --------------------------------------------------

static class Patterns {
    public static string Match(object o) => o switch {
        int i when i > 0 => "positive int",
        int => "int",
        string s => s,
        null => "null",
        _ => "other"
    };
}

// --------------------------------------------------
// LINQ
// --------------------------------------------------

class LinqTest {
    public static void Run() {
        var list = new List<int> {1,2,3,4};

        var query =
            from x in list
            where x % 2 == 0
            select x * x;

        var method = list
            .Where(x => x > 2)
            .Select(x => x * 2)
            .ToList();
    }
}

// --------------------------------------------------
// LAMBDAS / LOCAL FUNCTIONS
// --------------------------------------------------

class Lambdas {
    public static void Run() {
        Func<int,int,int> f = (a,b) => a + b;

        var complex = (int x) => {
            int Local(int y) => y * 2;
            return Local(x);
        };
    }
}

// --------------------------------------------------
// INTERPOLATED STRINGS (EDGE CASES)
// --------------------------------------------------

class Strings {
    public static void Run() {
        int x = 10;

        var s1 = $"Value: {x}";
        var s2 = $"Nested: {($"{x * 2}")}";
        var s3 = $"Format: {x,10:D}";
        var s4 = $@"Verbatim {x}\n";
        var s5 = $$"""Raw string {{ {x} }} """;

        // invalid (commented)
        // var bad = $" {x ";
    }
}

// --------------------------------------------------
// LITERALS
// --------------------------------------------------

class Literals {
    public static void Run() {
        int i = 1_000_000;
        int hex = 0xFF;
        int bin = 0b1010;

        double d = 1e-10;
        float f = 1.0f;
        decimal m = 1.0m;

        char c = '\n';
        string s = "text";
        string v = @"verbatim \n";
    }
}

// --------------------------------------------------
// OPERATORS / OVERLOADS
// --------------------------------------------------

struct Vec {
    public int X, Y;

    public static Vec operator +(Vec a, Vec b)
        => new Vec { X = a.X + b.X, Y = a.Y + b.Y };

    public static bool operator ==(Vec a, Vec b)
        => a.X == b.X && a.Y == b.Y;

    public static bool operator !=(Vec a, Vec b)
        => !(a == b);
}

// --------------------------------------------------
// ASYNC / AWAIT
// --------------------------------------------------

class AsyncTest {
    public static async System.Threading.Tasks.Task<int> Run() {
        await System.Threading.Tasks.Task.Delay(10);
        return 42;
    }
}

// --------------------------------------------------
// UNSAFE / POINTERS
// --------------------------------------------------

unsafe class UnsafeTest {
    public static void Run() {
        int x = 10;
        int* p = &x;
        *p = 20;
    }
}

// --------------------------------------------------
// EXCEPTIONS
// --------------------------------------------------

class Exceptions {
    public static void Run() {
        try {
            throw new Exception("error");
        }
        catch (InvalidOperationException ex) {
        }
        catch (Exception e) when (e.Message != null) {
        }
        finally {
        }
    }
}

// --------------------------------------------------
// SWITCH / CONTROL FLOW
// --------------------------------------------------

class Control {
    public static void Run(int n) {
        if (n > 0) { }
        else if (n < 0) { }

        for (int i = 0; i < 10; i++) { }

        while (n-- > 0) { }

        do { } while (n < 5);

        switch (n) {
            case 1:
                break;
            default:
                break;
        }
    }
}

// --------------------------------------------------
// INVALID / FALLBACK (COMMENTED)
// --------------------------------------------------

// var x = ;
// string s = "unterminated
// if (true
// var bad = new List<int>>();

// --------------------------------------------------
// ENTRY
// --------------------------------------------------

class Program {
    static void Main() {
        var p = new Person("Alice", 30);
        Console.WriteLine(p);

        LinqTest.Run();
        Lambdas.Run();
        Strings.Run();
    }
}