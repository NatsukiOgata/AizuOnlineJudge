// JOI - Prelim  0512
// シーザー暗号
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
    const unordered_map<char, char> map_from_to{
        {'D', 'A'},
        {'E', 'B'},
        {'F', 'C'},
        {'G', 'D'},
        {'H', 'E'},
        {'I', 'F'},
        {'J', 'G'},
        {'K', 'H'},
        {'L', 'I'},
        {'M', 'J'},
        {'N', 'K'},
        {'O', 'L'},
        {'P', 'M'},
        {'Q', 'N'},
        {'R', 'O'},
        {'S', 'P'},
        {'T', 'Q'},
        {'U', 'R'},
        {'V', 'S'},
        {'W', 'T'},
        {'X', 'U'},
        {'Y', 'V'},
        {'Z', 'W'},
        {'A', 'X'},
        {'B', 'Y'},
        {'C', 'Z'},
    };

    const auto S(cin2var<string>());
    for (const auto& c : S) {
        cout << map_from_to.at(c);
    }
    cout << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
