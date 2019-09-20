#include <bits/stdc++.h>

using namespace std;

template <typename T>
using vec1 = vector<T>;

template <typename T>
using vec2 = vec1<vec1<T>>;

template <typename T>
T Get(const vec2<T>& v2, size_t x, size_t y)
{
    return v2[y][x];
}

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
    const auto N(cin2var<size_t>());

    vec2<size_t> vec2checktable;
    for (size_t i = 0; i < N; ++i) {
        vec2checktable.push_back(cin2vec<size_t>(N));
    }

    vec1<size_t> lengths(N);

    vec1<size_t> ptns;
    for (size_t i = 0; i < N; ++i) {
        ptns.push_back(i);
    }

    do {
        for (size_t cur = 0; cur < ptns.size(); ++cur) {
            for (size_t tar = 0; tar < ptns.size(); ++tar) {
                if (cur == tar) continue;
                const auto cur_v = ptns[cur];
                const auto tar_v = ptns[tar];
                const auto length = Get(vec2checktable, cur_v, tar_v);
            }
        }
    } while (next_permutation(ptns.begin(), ptns.end()));

    return 0;
}
