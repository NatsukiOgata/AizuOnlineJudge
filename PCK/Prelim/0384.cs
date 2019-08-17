using System;
using System.Linq;
using System.Collections.Generic;
using System.Threading.Tasks;

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

    static T[] cin2arr<T>()
    {
        return cin2strs().Select(line => to<T>(line)).ToArray();
    }

    static void Main(string[] args)
    {
        int[] arr = cin2arr<int>();
        var A     = arr[0];
        var N     = arr[1];
        var M     = arr[2];
        // Console.WriteLine("{0} {1} {2}", A, N, M);
        var nos = new List<ulong>();
        for (var i = 1;; ++i) {
            var ret_pow = (ulong)Math.Pow(i + A, N);
            if (ret_pow > (ulong)M) break;
            nos.Add(ret_pow);
        }
        // foreach (var no in nos) {
        // 	Console.WriteLine(no);
        // }
        // Parallel.ForEach(nos, no => {
        //  	Console.WriteLine(no);
        // });
        var ret   = nos.AsParallel().Where(no => {
            var ints    = no.ToString().ToCharArray().Select(c => (int)char.GetNumericValue(c));
            var ret_pow = (ulong)Math.Pow(ints.Sum() + A, N);
            return no == ret_pow;
        });
        var count = ret.Count();
        Console.WriteLine("{0}", count);
    }
}
