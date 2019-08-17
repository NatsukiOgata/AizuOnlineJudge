using System;
using System.Linq;
// using System.Collections.Generic;
// using System.Threading.Tasks;

class Root
{
    static T to<T>(string str)
    {
        return (T)Convert.ChangeType(str, typeof(T));
    }

    static string cin2str()
    {
        return System.Console.ReadLine().Trim();
    }

    static string[] cin2strs()
    {
        return cin2str().Split(' ');
    }

    static T cin2var<T>()
    {
        return to<T>(cin2str());
    }

    static T[] cin2arr<T>()
    {
        return cin2strs().Select(line => to<T>(line)).ToArray();
    }

    static void Main(string[] args)
    {
        var N = cin2var<int>();
        for (var i = 0; i < N; ++i) {
            int[] stArrayData = cin2arr<int>();
            System.Console.WriteLine("hello = {0} , world = {1}", stArrayData[0], stArrayData[1]);
        }
    }
}
