#include <cmath>
#include <iostream>
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
    const int    N(cin2var<int>());
    const string S(cin2var<string>());
    string       line(S);
    line.resize(N);
    int count = 0;
    while (true) {
        const auto iteOX(line.find("OX"));
        const auto iteXO(line.find("XO"));
        if (iteOX == string::npos && iteXO == string::npos) break;
        const auto iteMin(min(iteOX, iteXO));
        line = line.substr(iteMin + 2);
        ++count;
    }
    cout << count << endl;
    return 0;
}
