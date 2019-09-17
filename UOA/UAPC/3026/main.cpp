#include <bits/stdc++.h>

using namespace std;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

void sub()
{
    const auto X(cin2var<size_t>());
    cout << "ai1333" << string(X / 100, '3') << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
