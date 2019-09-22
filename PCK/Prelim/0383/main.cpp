#include <iostream>

using namespace std;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

int calc(int A, int B, int X)
{
    int rest(X);
    if (rest <= 500) {
        return min(A, B);
    }
    else if (rest <= 1000) {
        return min(A, B * 2);
    }
    const double cospa1000 = 1000.0 / A;
    const double cospa500  =  500.0 / B;
    int cost = 0;
    if (cospa1000 > cospa500) {
        while (rest >= 1000) {
            rest -= 1000;
            cost += A;
        }
        if (rest <= 500) {
            cost += min(A, B);
            return cost;
        }
        else if (rest <= 1000) {
            cost += min(A, B * 2);
            return cost;
        }
    }
    else {
        while (rest > 0) {
            rest -= 500;
            cost += B;
        }
    }
    return cost;
}

int main()
{
    const int A(cin2var<int>());
    const int B(cin2var<int>());
    const int X(cin2var<int>());
    cout << calc(A, B, X) << endl;
    return 0;
}
