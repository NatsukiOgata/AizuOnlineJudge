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
    vec1<T> vec1;
    for (size_t i = 0; i < size; ++i) {
        vec1.push_back(cin2var<T>());
    }
    return vec1;
}

int main()
{
    while (true) {
        const auto N(cin2var<int>());
        if (!N) break;
        const auto hits(cin2vec<int>(N / 4));
        const auto sum = accumulate(hits.cbegin(), hits.cend(), 0);
        cout << sum << endl;
    }
    return 0;
}
