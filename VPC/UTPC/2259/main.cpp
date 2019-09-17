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
    const auto M(cin2var<size_t>());
    const auto N(cin2var<size_t>());

    vec1<tuple<int64_t, size_t>> vs;
    for (size_t i = 0; i < M; ++i) {
        const auto    As(cin2vec<int64_t>(N));
        const int64_t sum = accumulate(As.cbegin(), As.cend(), 0ull);
        vs.push_back(make_tuple(sum, i + 1));
    }
    sort(vs.rbegin(), vs.rend());

    cout << get<0>(vs.front()) << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
