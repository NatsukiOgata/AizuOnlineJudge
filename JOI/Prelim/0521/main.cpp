// JOI - Prelim  0521
// おつり
#include <bits/stdc++.h>

using namespace std;

using UInt = uint_fast64_t;

template <typename T>
using vec1 = vector<T>;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

const vec1<UInt> coins{500, 100, 50, 10, 5, 1};

bool sub()
{
    const auto price(cin2var<UInt>());

    if (!price) return false;

    UInt pay          = 1000 - price;
    UInt pay_out_coin = 0;
    for (const auto& coin : coins) {
        pay_out_coin += pay / coin;
        pay = pay % coin;
    }
    cout << pay_out_coin << endl;
    return true;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    while (sub());
    return 0;
}
