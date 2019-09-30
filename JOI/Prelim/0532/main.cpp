// JOI - Prelim  0532
// タイムカード
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using Int  = int_fast64_t;

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

template <typename T>
int get_hours(const T& chrono)
{
    return duration_cast<hours>(chrono).count() % 24;
}

template <typename T>
int get_minutes(const T& chrono)
{
    return duration_cast<minutes>(chrono).count() % 60;
}

template <typename T>
int get_seconds(const T& chrono)
{
    return duration_cast<seconds>(chrono).count() % 60;
}

void sub()
{
    const auto N = 3;
    for (auto i = 0u; i < N; ++i) {
        const auto Ss(cin2vec<Int>(3));
        const auto Es(cin2vec<Int>(3));
        const auto tp_s(hours(Ss[0]) + minutes(Ss[1]) + seconds(Ss[2]));
        const auto tp_e(hours(Es[0]) + minutes(Es[1]) + seconds(Es[2]));
        const auto d(tp_e - tp_s);
        cout << get_hours(d) << ' ' << get_minutes(d) << ' ' << get_seconds(d) << endl;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
