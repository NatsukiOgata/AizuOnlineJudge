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

string sub()
{
    const auto N(cin2var<size_t>());
    const auto Q(cin2var<size_t>());

    map<int, string> map_year_name;
    map_year_name[1] = "kogakubu10gokan";
    for (size_t i = 0; i < N; ++i) {
        const auto year(cin2var<int>());
        const auto name(cin2var<string>());
        map_year_name[year] = name;
    }

    {
        // Just
        const auto ite(map_year_name.find(Q));
        if (ite != map_year_name.end()) {
            return ite->second;
        }
    }

    // 要素を追加し、一つ前
    auto ite(map_year_name.emplace(Q, "").first);
    --ite;
    return ite->second;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << sub() << endl;
    return 0;
}
