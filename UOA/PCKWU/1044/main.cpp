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

template <typename Iterator>
string Join(const Iterator& cbegin, const Iterator& cend, const string& delim = "")
{
    ostringstream os;
    copy(cbegin, cend, ostream_iterator<string>(os, delim.c_str()));
    string str(os.str());
    if (!str.empty()) {
        str.erase(str.size() - delim.size());
    }
    return str;
}

bool matchWordsByUS(const string& str, vec1<string>& words)
{
    int   start = 0;
    regex ptn("_|$");
    for (sregex_iterator ite(str.cbegin(), str.cend(), ptn), end; ite != end; ++ite) {
        auto&&     m(*ite);
        const auto word(str.substr(start, m.position() - start));
        if (str == word) break;
        if (word.empty()) continue;
        words.push_back(word);
        start = m.position() + 1;  // マッチ箇所を含まない
    }
    return !words.empty();
}

bool matchWordsByCC(const string& str, vec1<string>& words)
{
    int   start = 0;
    regex ptn("[A-Z]|$");
    for (sregex_iterator ite(str.cbegin(), str.cend(), ptn), end; ite != end; ++ite) {
        auto&&     m(*ite);
        const auto word(str.substr(start, m.position() - start));
        if (word.empty()) continue;
        words.push_back(word);
        start = m.position();
    }
    return !words.empty();
}

void ConvUCC(vec1<string>& words)
{
    for (auto& word : words) {
        char& c(word.front());
        c = toupper(c);
    }
}

void ConvLCC(vec1<string>& words)
{
    for (auto ite(words.begin()); ite != words.end(); ++ite) {
        char& c(ite->front());
        if (ite == words.begin()) {
            c = tolower(c);
        }
        else {
            c = toupper(c);
        }
    }
}

void ConvUS(vec1<string>& words)
{
    for (auto& word : words) {
        char& c(word.front());
        c = tolower(c);
    }
}

int main()
{
    while (true) {
        const auto N(cin2var<string>());
        const auto T(cin2var<string>());
        const char t(T.front());
        if (t == 'X') break;
        vec1<string> words;
        matchWordsByUS(N, words) || matchWordsByCC(N, words);
        switch (t) {
        case 'U':
            ConvUCC(words);
            cout << Join(words.cbegin(), words.cend()) << endl;
            break;
        case 'L':
            ConvLCC(words);
            cout << Join(words.cbegin(), words.cend()) << endl;
            break;
        case 'D':
            ConvUS(words);
            cout << Join(words.cbegin(), words.cend(), "_") << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
