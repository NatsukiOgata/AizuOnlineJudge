using System;
using System.Linq;
using System.Collections.Generic;

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

    static void Swap<T>(ref T lhs, ref T rhs)
    {
        T temp = lhs;
        lhs    = rhs;
        rhs    = temp;
    }

    static void Main(string[] args)
    {
        var N   = cin2var<int>();
        int[] A = cin2arr<int>();

        var ans = new List<int>(A);
        ans.Sort();

        var match_count = 0;
        for (var i = 0; i < N; ++i) {
            if (A[i] == ans[i]) ++match_count;
        }

        if (match_count == N) {
            Console.WriteLine("0");
            return;
        }

        var Q = cin2var<int>();
        for (var i = 0; i < Q; ++i) {
            int[] P = cin2arr<int>();
            var  l  = P[0] - 1;
            var  r  = P[1] - 1;
            bool ml = A[l] == ans[l];
            bool mr = A[r] == ans[r];
            Swap<int>(ref A[l], ref A[r]);
            bool ml2 = A[l] == ans[l];
            bool mr2 = A[r] == ans[r];
            if (ml && !ml2) --match_count;
            if (mr && !mr2) --match_count;
            if (!ml && ml2) ++match_count;
            if (!mr && mr2) ++match_count;
            if (match_count == N) {
                Console.WriteLine("{0}", i + 1);
                return;
            }
        }

        Console.WriteLine("-1");
    }
}
