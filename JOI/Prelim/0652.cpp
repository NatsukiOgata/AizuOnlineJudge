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
    const int A(cin2var<int>());
    const int B(cin2var<int>());
    const int C(cin2var<int>());
    int coin = 0;
    int day = 1;
    for (; coin < C; ++day) {
        coin += A;
        if (day % 7 == 0) {
            coin += B;
        }
    }
    --day;
    cout << day << endl;
    return 0;
}
