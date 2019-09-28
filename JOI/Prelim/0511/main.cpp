// JOI - Prelim  0511
// 未提出者は誰だ
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
    const auto Ns(cin2vec<int64_t>(28));

    unordered_set<int64_t> set_n(Ns.cbegin(), Ns.cend());
    for (size_t i = 1; i <= 30; ++i) {
        if (set_n.count(i)) continue;
        cout << i << endl;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
