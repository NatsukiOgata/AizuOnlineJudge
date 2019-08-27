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

struct Immutable
{
    size_t     W;
    size_t     H;
    vec2<char> vec2map;
    string     pattern;
};

struct Mutable
{
    vec2<int> vec2map;
    int       max_count;
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
    if (now <= count) return;
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

bool MoveG(int count, size_t& x, size_t& y)
{
    Mutable& mt(mt_);
    if (Get(mt.vec2map, x, y) <= count) return true;
    const Immutable& it(it_);
    const size_t     pos = count % it.pattern.size();
    const char       act = it.pattern.at(pos);
    switch (act) {
    case '5':
        // 何もしない
        return false;
    case '8':
        if (y > 0) {
            --y;
        }
        return false;
    case '6':
        if (x < it.W - 1) {
            ++x;
        }
        return false;
    case '4':
        if (x > 0) {
            --x;
        }
        return false;
    case '2':
        if (y < it.H - 1) {
            ++y;
        }
        return false;
    default:
        assert(!"act");
        return false;
    }
}

bool sub()
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

    mt_.vec2map = InitVec2<int>(it_.W, it_.H, INT_MAX);

    size_t a_x = 0;
    size_t a_y = 0;
    if (!Find(it_.vec2map, 'A', a_x, a_y)) {
        assert(!"Not found A");
        return false;
    }

    // 移動距離を求める
    Hosuu(a_x, a_y, 0);

    size_t b_x = 0;
    size_t b_y = 0;
    if (!Find(it_.vec2map, 'B', b_x, b_y)) {
        assert(!"Not found B");
        return false;
    }

    // 調査するターン数を決める
    const int  pattern_size = it_.pattern.size();
    const int  g_count      = pattern_size * (pattern_size + 1);
    const auto count        = max(mt_.max_count, g_count);

    // ゴーストを動かす
    for (int i = 0; i <= count; ++i) {
        if (MoveG(i, b_x, b_y)) {
            cout << i << ' ' << b_y << ' ' << b_x << endl;
            return true;
        }
    }

    cout << "impossible" << endl;
    return true;
}

int main()
{
    while (true) {
        if (!sub()) {
            break;
        }
    }

    return 0;
}
