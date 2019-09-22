#include <iostream>

using namespace std;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

int main()
{
    const int F(cin2var<int>());
    const int C = (F - 30) / 2;
    cout << C << endl;
    return 0;
}
