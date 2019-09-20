#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

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
    vec1<T> vec1;
    for (size_t i = 0; i < size; ++i) {
        vec1.push_back(cin2var<T>());
    }
    return vec1;
}

int main()
{
    using Table  = tuple<int, int>;
    using Tables = vec1<Table>;
    Tables tables;

    vec1<int> counts;

    const int N(cin2var<int>());
    for (int i = 0; i < N; ++i) {
        const int       S(cin2var<int>());
        const vec1<int> Cs(cin2vec<int>(S));
        for (int c : Cs) {
            tables.push_back(make_tuple(c, i));
        }
        counts.push_back(i);
    }

    sort(tables.begin(), tables.end(), [](const auto& l, const auto& r) {
        // 0:降順
        // 1:昇順
        if (get<0>(l) > get<0>(r)) return true;
        if (get<0>(l) < get<0>(r)) return false;
        return get<1>(l) < get<1>(r);
    });

    int total = 0;
    for (const auto& table : tables) {
        const int count(get<1>(table));
        bool continue2 = false;
        for (int i = count; i < N; ++i) {
            if (counts[i] == 0) {
                continue2 = true;
                break;
            }
        }
        if (continue2) {
            continue;
        }
        for (int i = count; i < N; ++i) {
            --counts[i];
        }
        const int cost(get<0>(table));
        total += cost;
    }

    cout << total << endl;

    return 0;
}
