#include <bits/stdc++.h>

using namespace std;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

void sub()
{
    const auto N(cin2var<uint64_t>());
    size_t max = 0;
    for (uint64_t i = 0; i <= N; ++i) {
        const bitset<64> bs(i);
        if (max < bs.count()) max = bs.count();
    }
    cout << max << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
