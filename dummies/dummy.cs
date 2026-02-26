// omelette
using System;
using System.Collections.Generic;

class Person {
    public string Name { get; set; }
    public Person(string n){ Name=n; }
    public void Greet() => Console.WriteLine($"Hello {Name}");
}

class Program {
    static int Add(int a,int b)=>a+b;

    static void Main() {
        int x=5;
        double y=3.14;
        bool ok=true;
        string s="Hi";

        var list = new List<int>{1,2,3};
        var p = new Person("Alice");
        p.Greet();

        for(int i=0;i<2;i++)
            Console.WriteLine(i + (i%2==0?" even":" odd"));

        Console.WriteLine(Add(2,3));
    }
}