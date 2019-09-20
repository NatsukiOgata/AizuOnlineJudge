#include <bits/stdc++.h>

using namespace std;

template <typename T>
using vec1 = vector<T>;

string cin2line()
{
    string s;
    getline(cin, s);
    return s;
}

vec1<string> Split(const string& str, char sep)
{
    vec1<string> v;
    stringstream ss(str + sep);
    string       line;
    while (getline(ss, line, sep)) {
        v.push_back(line);
    }
    return v;
}

int main()
{
    while (true) {
        const string S(cin2line());
        if (S == "END OF INPUT") break;
        const auto strs(Split(S, ' '));
        for (const auto& str : strs) {
            cout << str.size();
        }
        cout << endl;
    }
    return 0;
}
