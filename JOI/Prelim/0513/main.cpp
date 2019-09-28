// JOI - Prelim  0513
// カードの並び替え
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

void cut(int64_t k, deque<int64_t>& cards)
{
    for (auto i = 0; i < k; ++i) {
        const auto& c = cards.front();
        cards.push_back(c);
        cards.pop_front();
    }
}

void ri_full_shuffle(int64_t n, deque<int64_t>& cards)
{
    auto iteA(cards.cbegin());
    auto iteB(next(iteA, n));

    deque<int64_t> new_cards;
    while (iteB != cards.cend()) {
        new_cards.push_back(*iteA++);
        new_cards.push_back(*iteB++);
    }
    swap(cards, new_cards);
}

void sub()
{
    const auto N(cin2var<size_t>());
    const auto M(cin2var<size_t>());
    const auto Ms(cin2vec<int64_t>(M));

    deque<int64_t> cards;
    for (size_t i = 0; i < N * 2; ++i) {
        cards.push_back(i + 1);
    }
    for (const auto& m : Ms) {
        if (m) {
            cut(m, cards);
        }
        else {
            ri_full_shuffle(N, cards);
        }
    }
    for (const auto& n : cards) {
        cout << n << endl;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
