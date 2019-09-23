// JOI - Prelim  0631
// ポイントカード (Point Card)
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

void sub()
{
    const auto N(cin2var<int64_t>());
    const auto M(cin2var<int64_t>());

    int64_t ok_count = 0;

    using AB = tuple<int64_t, int64_t>;
    priority_queue<AB> abs;
    for (auto i = 0; i < M; ++i) {
        const auto A(cin2var<int64_t>());
        const auto B(cin2var<int64_t>());
        if (N <= A) {
            // 交換可能
            ++ok_count;
            continue;
        }
        abs.push(make_tuple(A, B));
    }

    int64_t ans = 0;
    while (M - 1 > ok_count) {
        const auto& ab(abs.top());
        ans += N - get<0>(ab);
        ++ok_count;
        abs.pop();
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
