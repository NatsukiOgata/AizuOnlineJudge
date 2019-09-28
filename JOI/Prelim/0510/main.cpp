// JOI - Prelim  0510
// 得点
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
    const auto As(cin2vec<int64_t>(4));
    const auto Bs(cin2vec<int64_t>(4));

    const int64_t sumA = accumulate(As.cbegin(), As.cend(), 0ll);
    const int64_t sumB = accumulate(Bs.cbegin(), Bs.cend(), 0ll);

    const int64_t ans = max(sumA, sumB);
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
