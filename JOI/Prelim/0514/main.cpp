// JOI - Prelim  0514
// 品質検査
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
    const auto AN(cin2var<size_t>());
    const auto BN(cin2var<size_t>());
    const auto CN(cin2var<size_t>());
    const auto N(cin2var<size_t>());
    vec1<tuple<int64_t, set<int64_t>>> setABCs;
    for (size_t i = 0; i < N; ++i) {
        const auto Rs(cin2vec<int64_t>(4));
        set<int64_t> setABC{Rs.cbegin(), prev(Rs.cend())};
        int64_t result = *Rs.rbegin();
        setABCs.push_back(make_tuple(result, move(setABC)));
    }
    sort(setABCs.rbegin(), setABCs.rend()); // 合格したものが先に並ぶ
    map<int64_t, int64_t> map_result;
    for (const auto& setABC : setABCs) {
        if (!get<0>(setABC)) break; // 不合格
        const auto& abc(get<1>(setABC));
        for (const auto& s : abc) {
            map_result[s] = 1;
        }
    }
    for (const auto& setABC : setABCs) {
        if (get<0>(setABC)) continue; // 合格
        const auto& abc(get<1>(setABC));
        int oks = 0;
        int64_t ng_no = 0;
        for (const auto& s : abc) {
            auto ite(map_result.find(s));
            if (ite != map_result.end() && ite->second == 1) {
                ++oks;
            }
            else {
                ng_no = s;
            }
        }
        if (oks == 2) {
            // 故障が確定
            map_result[ng_no] = 1;
        }
    }
    for (size_t i = 1; i <= AN + BN + CN; ++i) {
        const auto ite(map_result.find(i));
        int ans = 0;
        if (ite == map_result.end()) {
            ans = 2;
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
