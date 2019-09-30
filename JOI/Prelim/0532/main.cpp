// JOI - Prelim  0532
// タイムカード
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using Int  = int_fast64_t;
using UInt = uint_fast64_t;

template <typename T>
using vec1 = vector<T>;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

template <typename T>
vec1<T> cin2vec(size_t size)
{
    vec1<T> vec1(size);
    for (auto& v : vec1) {
        v = cin2var<T>();
    }
    return vec1;
}

void sub()
{
    const auto N = 3;
    for (auto i = 0u; i < N; ++i) {
        const auto Ss(cin2vec<Int>(3));
        const auto Es(cin2vec<Int>(3));

        system_clock::time_point tp_s;
        tp_s +=   hours(Ss[0]);
        tp_s += minutes(Ss[1]);
        tp_s += seconds(Ss[2]);
        system_clock::time_point tp_e;
        tp_e +=   hours(Es[0]);
        tp_e += minutes(Es[1]);
        tp_e += seconds(Es[2]);

        const auto d(tp_e - tp_s);
        cout << duration_cast<hours>(d).count() << ' ';
        cout << duration_cast<minutes>(d).count() % 60 << ' ';
        cout << duration_cast<seconds>(d).count() % 60 << endl;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
