// JOI - Prelim  0522
// JOIとIOI
#include <bits/stdc++.h>

using namespace std;

using UInt = uint_fast64_t;

template <typename T>
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

UInt find_count(const string& src, const string& ptn)
{
    UInt ret = 0;
    string::size_type pos = 0;
    while (true) {
        pos = src.find(ptn, pos);
        if (string::npos == pos) {
            break;
        }
        else {
            ++ret;
            ++pos;
        }
    }
    return ret;
}

bool sub()
{
    const auto S(cin2var<string>());

    if (S.empty()) return false;

    cout << find_count(S, "JOI") << endl;
    cout << find_count(S, "IOI") << endl;

    return true;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    while (sub());
    return 0;
}
