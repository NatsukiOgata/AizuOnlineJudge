// JOI - Prelim  0641
// 鉛筆 (Pencils)
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
    const auto N(cin2var<size_t>());
    const auto A(cin2var<size_t>());
    const auto B(cin2var<size_t>());
    const auto C(cin2var<size_t>());
    const auto D(cin2var<size_t>());

    const auto div_x = ceil(N / static_cast<double>(A));
    const auto sum_x = div_x * B;
    const auto div_y = ceil(N / static_cast<double>(C));
    const auto sum_y = div_y * D;
    const auto ans   = min(sum_x, sum_y);

    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
