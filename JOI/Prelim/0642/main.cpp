// JOI - Prelim  0642
// 双六 (Sugoroku)
#include <bits/stdc++.h>

using namespace std;

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
    const auto N(cin2var<size_t>());
    const auto As(cin2vec<char>(N));
    uint64_t c1 = 0;
    uint64_t max_c1 = 0;
    for (const auto& c : As) {
        if (c == '1') {
            ++c1;
            if (max_c1 < c1) max_c1 = c1;
        }
        else {
            c1 = 0;
        }
    }
    cout << max_c1 + 1 << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
