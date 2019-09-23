// JOI - Prelim  0630
// 電子レンジ (Microwave)
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
    // 1 行目には、もともとの肉の温度 A が書かれている
    // 2 行目には、目的の温度 B が書かれている
    // 3 行目には、凍った肉を1度温めるのにかかる時間 C が書かれている
    // 4 行目には、凍った肉を解凍するのにかかる時間 D が書かれている
    // 5 行目には、凍っていない肉を1度温めるのにかかる時間 E が書かれている
    const auto A(cin2var<int64_t>());
    const auto B(cin2var<int64_t>());
    const auto C(cin2var<int64_t>());
    const auto D(cin2var<int64_t>());
    const auto E(cin2var<int64_t>());

    int64_t  a = 0;
    uint64_t t = 0;
    for (a = A; a < 0; ++a) {
        t += C;
    }
    if (A <= 0) {
        t += D;
    }
    for (auto i = a; i < B; ++i) {
        t += E;
    }
    cout << t << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
