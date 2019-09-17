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

    using BA = tuple<int64_t, int64_t>;
    vec1<BA> bas;
    for (size_t i = 0; i < N; ++i) {
        const auto ab(cin2vec<int64_t>(2));
        if (ab[0] > ab[1]) continue;  // 絶対に負ける
        bas.push_back(make_tuple(ab[1], ab[0]));
    }

    sort(bas.begin(), bas.end());

    int64_t time = 0;
    int64_t win  = 0;
    for (const auto& ba : bas) {
        if (time + get<1>(ba) <= get<0>(ba)) {
            time += get<1>(ba);
            ++win;
        }
    }
    cout << win << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
