#include <algorithm>
#include <iostream>
#include <unordered_map>
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
    const int       N(cin2var<int>());
    const vec1<int> A(cin2vec<int>(N));
    vec1<int>       as(A);
    auto            ite(as.begin());
    while (true) {
        ite = adjacent_find(ite, as.end());
        if (ite == as.end()) {
            break;
        }
        as.erase(ite);
    }
    unordered_map<int, int> datas;
    for (int a : as) {
        ++datas[a];
    }
    const auto itemax(
        max_element(datas.cbegin(), datas.cend(), [](const auto& l, const auto& r) { return l.second < r.second; }));
    const auto& datamax(*itemax);
    cout << datamax.second << endl;
    return 0;
}
