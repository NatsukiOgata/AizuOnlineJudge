// JOI - Prelim  0514
// 品質検査
#include <bits/stdc++.h>

using namespace std;

using Int  = int_fast64_t;
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

template <typename T>
vec1<T> cin2vec(UInt size)
{
    vec1<T> vec1(size);
    for (auto& v : vec1) {
        v = cin2var<T>();
    }
    return vec1;
}

enum
{
    NG,
    OK,
    UNKNOWN,
};

void sub()
{
    const auto AN(cin2var<UInt>());
    const auto BN(cin2var<UInt>());
    const auto CN(cin2var<UInt>());
    const auto N(cin2var<UInt>());

    priority_queue<tuple<Int, set<Int>>> pqABC;
    for (auto i = 0u; i < N; ++i) {
        const auto Rs(cin2vec<Int>(3));
        const auto Re(cin2var<Int>());
        set<Int>   setABC{Rs.cbegin(), Rs.cend()};
        pqABC.push(make_tuple(Re, move(setABC)));
    }
    map<Int, Int> map_result;
    for (; !pqABC.empty(); pqABC.pop()) {
        const auto& setABC(pqABC.top());
        if (!get<0>(setABC)) break;  // 不合格
        const auto& abc(get<1>(setABC));
        // 完動品
        for (const auto& s : abc) {
            map_result[s] = OK;
        }
    }
    for (; !pqABC.empty(); pqABC.pop()) {
        const auto& setABC(pqABC.top());
        const auto& abc(get<1>(setABC));
        int         oks   = 0;
        Int         ng_no = 0;
        for (const auto& s : abc) {
            const auto ite(map_result.find(s));
            if (ite != map_result.cend() && ite->second == OK) {
                ++oks;
            }
            else {
                ng_no = s;
            }
        }
        if (oks == 2) {
            // 故障が確定
            map_result[ng_no] = NG;
        }
    }
    for (auto i = 1u; i <= AN + BN + CN; ++i) {
        const auto ite(map_result.find(i));
        int        ans = 0;
        if (ite == map_result.cend()) {
            ans = UNKNOWN;
        }
        else {
            ans = ite->second;
        }
        cout << ans << endl;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
