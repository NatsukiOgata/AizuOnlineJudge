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
    const vec1<int> Xs(cin2vec<int>(2));
    cout << abs(Xs[0] - Xs[1]) << endl;
    return 0;
}
