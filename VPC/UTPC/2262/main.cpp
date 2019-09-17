#include <bits/stdc++.h>

using namespace std;

template <typename T>
using vec1 = vector<T>;

template <typename T>
using vec2 = vec1<vec1<T>>;

template <typename T>
T Get(const vec2<T>& v2, size_t x, size_t y)
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

template <typename T>
vec1<T> cin2vec(size_t size)
{
    vec1<T> vec1(size);
    for (auto& v : vec1) {
        v = cin2var<T>();
    }
    return vec1;
}

enum class VecType
{
    Up,
    Down,
    Left,
    Right,
};

using VisitInfo = tuple<size_t, size_t, VecType, char>;

size_t         R_;
size_t         C_;
vec2<char>     vec2_prog_;
set<VisitInfo> set_visit_;

size_t GetUp(size_t y)
{
    if (y == 0) y = R_;
    return y - 1;
}

size_t GetDown(size_t y)
{
    ++y;
    if (y >= R_) y = 0;
    return y;
}

size_t GetLeft(size_t x)
{
    if (x == 0) x = C_;
    return x - 1;
}

size_t GetRight(size_t x)
{
    ++x;
    if (x >= C_) x = 0;
    return x;
}

// prototype
void Run(size_t x, size_t y, VecType vt, char mem);

void Next(size_t x, size_t y, VecType vt, char mem)
{
    switch (vt) {
    case VecType::Up:
        Run(x, GetUp(y), vt, mem);
        break;
    case VecType::Down:
        Run(x, GetDown(y), vt, mem);
        break;
    case VecType::Left:
        Run(GetLeft(x), y, vt, mem);
        break;
    case VecType::Right:
        Run(GetRight(x), y, vt, mem);
        break;
    }
}

// 発見！
class found : exception
{
};

void Run(size_t x, size_t y, VecType vt, char mem)
{
    {
        const VisitInfo vi(make_tuple(x, y, vt, mem));
        if (!set_visit_.insert(vi).second) {
            // 同じ条件で通過済み
            return;
        }
    }
    const auto c = Get(vec2_prog_, x, y);
    // cout << c << ' ' << static_cast<int>(mem) << endl;
    switch (c) {
    case '<':
        vt = VecType::Left;
        Next(x, y, vt, mem);
        break;
    case '>':
        vt = VecType::Right;
        Next(x, y, vt, mem);
        break;
    case '^':
        vt = VecType::Up;
        Next(x, y, vt, mem);
        break;
    case 'v':
        vt = VecType::Down;
        Next(x, y, vt, mem);
        break;
    case '_':
        vt = mem == 0 ? VecType::Right : VecType::Left;
        Next(x, y, vt, mem);
        break;
    case '|':
        vt = mem == 0 ? VecType::Down : VecType::Up;
        Next(x, y, vt, mem);
        break;
    case '?':
        Run(GetLeft(x), y, VecType::Left, mem);
        Run(GetRight(x), y, VecType::Right, mem);
        Run(x, GetUp(y), VecType::Up, mem);
        Run(x, GetDown(y), VecType::Down, mem);
        break;
    case '@':
        throw found();
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        mem = c - '0';
        assert(0 <= mem && mem <= 9);
        // break;
    case '.':
        Next(x, y, vt, mem);
        break;
    case '+':
        if (++mem > 15) mem = 0;
        Next(x, y, vt, mem);
        break;
    case '-':
        if (--mem < 0) mem = 15;
        Next(x, y, vt, mem);
        break;
    default:
        assert(!"switch");
        return;
    }
}

void sub()
{
    R_ = cin2var<size_t>();
    C_ = cin2var<size_t>();
    for (size_t i = 0; i < R_; ++i) {
        const auto vec1(cin2vec<char>(C_));
        vec2_prog_.push_back(vec1);
    }
    string ans;
    try {
        Run(0, 0, VecType::Right, 0);
        ans = "NO";
    }
    catch (found& ex) {
        ans = "YES";
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sub();
    return 0;
}
