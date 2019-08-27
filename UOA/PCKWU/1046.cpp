#include <bits/stdc++.h>

using namespace std;

template <typename T>
using vec1 = vector<T>;

template <typename T>
using vec2 = vec1<vec1<T>>;

template <typename T>
vec2<T> InitVec2(size_t x, size_t y, const T& i = T())
{
    return vec2<T>(y, vec1<T>(x, i));
}

template <typename T>
T Get(const vec2<T>& v2, size_t x, size_t y)
{
    return v2[y][x];
}

template <typename T>
T& Ref(vec2<T>& v2, size_t x, size_t y)
{
    return v2[y][x];
}

template <typename T>
bool Find(const vec2<T>& v2, const T& val, size_t& x, size_t& y)
{
    for (y = 0; y < v2.size(); ++y) {
        for (x = 0; x < v2.front().size(); ++x) {
            if (Get(v2, x, y) == val) return true;
        }
    }
    return false;
}

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

template <typename T>
string Join(const vec1<T>& vec, const string& delim = "")
{
    vec1<string> strs;
    strs.reserve(vec.size());
    transform(vec.cbegin(), vec.cend(), back_inserter(strs), [](const T& v) { return to_string(v); });
    return Join(strs.begin(), strs.end(), delim);
}

template <>
string Join(const vec1<string>& strs, const string& delim)
{
    return Join(strs.begin(), strs.end(), delim);
}

struct Immutable
{
    size_t     W;
    size_t     H;
    vec2<char> vec2map;
    string     pattern;
    size_t     A_X;
    size_t     A_Y;
    size_t     B_X;
    size_t     B_Y;
};

struct Mutable
{
    vec2<int> vec2map;
    int       max_count;
    size_t    b_x;
    size_t    b_y;
};

Immutable it_{};
Mutable   mt_{};

void Hosuu(size_t x, size_t y, int count)
{
    const Immutable& it(it_);
    const auto&      c_now(Get(it.vec2map, x, y));
    if (c_now == '#') return;
    Mutable& mt(mt_);
    auto&    now(Ref(mt.vec2map, x, y));
    if (now < count) return;
    now = count;
    if (mt.max_count < now) {
        mt.max_count = now;
    }
    if (y > 0) {
        Hosuu(x, y - 1, count + 1);
    }
    if (x < it.W - 1) {
        Hosuu(x + 1, y, count + 1);
    }
    if (y < it.H - 1) {
        Hosuu(x, y + 1, count + 1);
    }
    if (x > 0) {
        Hosuu(x - 1, y, count + 1);
    }
}

bool MoveG(int count)
{
    Mutable& mt(mt_);
    if (Get(mt.vec2map, mt.b_x, mt.b_y) <= count) return true;
    const Immutable& it(it_);
    const size_t pos = count % it.pattern.size();
    const char act = it.pattern.at(pos);
    switch (act) {
        case '5':
            // 何もしない
            return false;
        case '8':
            if (mt.b_y > 0) {
                --mt.b_y;
            }
            return false;
        case '6':
            if (mt.b_x < it.W - 1) {
                ++mt.b_x;
            }
            return false;
        case '4':
            if (mt.b_x > 0) {
                --mt.b_x;
            }
            return false;
        case '2':
            if (mt.b_y < it.H - 1) {
                ++mt.b_y;
            }
            return false;
        default:
            assert(!"act");
            return false;
    }
}

bool main_sub()
{
    it_.H = (cin2var<size_t>());
    it_.W = (cin2var<size_t>());
    if (!it_.H && !it_.W) {
        return false;
    }

    it_.vec2map.clear();
    for (size_t i = 0; i < it_.H; ++i) {
        it_.vec2map.push_back(cin2vec<char>(it_.W));
    }
    it_.pattern = cin2var<string>();

    // for (const auto& vec1map : it_.vec2map) {
    //    for (const auto& map : vec1map) {
    //        cout << map;
    //    }
    //    cout << endl;
    //}

    mt_.vec2map = InitVec2<int>(it_.W, it_.H, INT_MAX);

    // for (const auto& vec1map : mt_.vec2map) {
    //    for (const auto& map : vec1map) {
    //        cout << map;
    //    }
    //    cout << endl;
    //}

    if (!Find(it_.vec2map, 'A', it_.A_X, it_.A_Y)) {
        return false;
    }

    if (!Find(it_.vec2map, 'B', it_.B_X, it_.B_Y)) {
        return false;
    }

    // cout << it_.A_X << ' ' << it_.A_Y << endl;
    // cout << it_.B_X << ' ' << it_.B_Y << endl;

    // Ref(mt_.vec2map, it_.A_X, it_.A_Y) = 0;
    Hosuu(it_.A_X, it_.A_Y, 0);

    // for (const auto& vec1map : mt_.vec2map) {
    //    for (const auto& map : vec1map) {
    //        cout << map << ' ';
    //    }
    //    cout << endl;
    //}

    mt_.b_x = it_.B_X;
    mt_.b_y = it_.B_Y;

    for (int i = 0; i <= mt_.max_count; ++i) {
        if (MoveG(i)) {
            cout << i << ' ' << mt_.b_y << ' ' << mt_.b_x << endl;
            return true;
        }
    }
    cout << "impossible" << endl;

    return true;
}

int main()
{
    while (true) {
        if (!main_sub()) {
            break;
        }
    }

    return 0;
}
