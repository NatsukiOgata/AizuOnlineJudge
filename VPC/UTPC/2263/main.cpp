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

using AB = tuple<int64_t, int64_t>;
using BA = tuple<int64_t, int64_t>;

void sub()
{
    const auto N(cin2var<size_t>());

    vec1<AB> abs;
    vec1<BA> bas;
    vec1<AB> cs;
    for (size_t i = 0; i < N; ++i) {
        const auto ab(cin2vec<int64_t>(2));
        if (ab[0] > ab[1]) continue;  // 絶対に負ける
        abs.push_back(make_tuple(ab[0], ab[1]));
        bas.push_back(make_tuple(ab[1], ab[0]));
        cs.push_back(make_tuple(ab[0], ab[1]));
    }

    sort(abs.begin(), abs.end());
    sort(bas.begin(), bas.end());
    sort(cs.begin(), cs.end(), [](const auto& l, const auto& r) {
            const auto& la(get<0>(l));
            const auto& lb(get<1>(l));
            const auto& ra(get<0>(r));
            const auto& rb(get<1>(r));
            const auto lab(la + lb);
            const auto rab(ra + rb);
            if (lab != rab) return lab < rab;
            if (lb != rb) return lb < rb;
            return la < rb;
    });

    // プランA
    int64_t winA = 0;
    {
        int64_t time = 0;
        for (const auto& ab : abs) {
            if (time + get<0>(ab) <= get<1>(ab)) {
                time += get<0>(ab);
                ++winA;
            }
        }
    }
    // プランB
    int64_t winB = 0;
    {
        int64_t time = 0;
        for (const auto& ba : bas) {
            if (time + get<1>(ba) <= get<0>(ba)) {
                time += get<1>(ba);
                ++winB;
            }
        }
    }
    // プランC
    int64_t winC = 0;
    {
        int64_t time = 0;
        for (const auto& c : cs) {
            if (time + get<0>(c) <= get<1>(c)) {
                time += get<0>(c);
                ++winC;
            }
        }
    }

    cout << max({winA, winB, winC}) << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
