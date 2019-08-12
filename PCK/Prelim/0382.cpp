#include <iostream>
#include <numeric>
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
    const int       C(cin2var<int>());
    const vec1<int> P(cin2vec<int>(C));
    const int       sum = accumulate(P.cbegin(), P.cend(), 0);
    const int       N1  = N + 1;
    int result = sum / N1;
    if (sum % N1 > 0) {
        ++result;
    }
    cout << result << endl;
    return 0;
}
