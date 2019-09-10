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
    vec1<T> vec1;
    for (size_t i = 0; i < size; ++i) {
        vec1.push_back(cin2var<T>());
    }
    return vec1;
}

void sub()
{
    constexpr size_t N = 3;
    const auto lunchs(cin2vec<size_t>(N));
    const auto iteMax(max_element(lunchs.cbegin(), lunchs.cend()));
    const char no = iteMax - lunchs.cbegin();
    cout << static_cast<char>('A' + no) << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
