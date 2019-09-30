// JOI - Prelim  0515
// 通学経路
#include <bits/stdc++.h>

using namespace std;

using Int  = int_fast64_t;
using UInt = uint_fast64_t;

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
T cin2var()
{
    T val;
    cin >> val;
    return val;
}

const array<Int, 2> dx{1, 0};
const array<Int, 2> dy{0, 1};

UInt       A_ = 0;
UInt       B_ = 0;
vec2<char> vec2map_;
UInt       goal_count = 0;

void move(UInt x, UInt y)
{
    if (x == A_ - 1 && y == B_ - 1) {
        ++goal_count;
        return;
    }
    if (x >= A_ || y >= B_) {
        return;
    }
    if (!Get(vec2map_, x, y)) {
        return;
    }
    for (auto i = 0u; i < dx.size(); ++i) {
        const auto nx = x + dx[i];
        const auto ny = y + dy[i];
        move(nx, ny);
    }
}

bool sub()
{
    A_ = cin2var<UInt>();
    B_ = cin2var<UInt>();

    if (!A_ || !B_) return false;

    vec2map_ = InitVec2<char>(A_, B_, 1);

    const auto N(cin2var<UInt>());
    for (auto i = 0u; i < N; ++i) {
        const auto X(cin2var<UInt>() - 1);
        const auto Y(cin2var<UInt>() - 1);
        Ref(vec2map_, X, Y) = 0;
    }

    goal_count = 0;
    move(0, 0);
    cout << goal_count << endl;

    return true;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    while (sub());
    return 0;
}
