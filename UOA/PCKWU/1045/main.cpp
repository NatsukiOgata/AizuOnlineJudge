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

template <typename T>
vec1<T> cin2vec(size_t size)
{
    vec1<T> vec1;
    for (size_t i = 0; i < size; ++i) {
        vec1.push_back(cin2var<T>());
    }
    return vec1;
}

template <typename T>
T ToGrayCode(T num)
{
    return num ^ (num >> 1);
}

using bs24 = bitset<24>;

int FindBit(const bs24& bs)
{
    for (size_t i = 0; i < 24; ++i) {
        if (bs.test(i)) {
            return i;
        }
    }
    return -1;
}

int main()
{
    while (true) {
        const auto N(cin2var<size_t>());
        if (!N) break;
        const auto   Ns(cin2vec<int>(N));
        const size_t count     = 1 << N;
        int          sum_a     = 0;
        int          sum_b     = accumulate(Ns.begin(), Ns.end(), 0);
        int          diff_min  = sum_b;
        size_t       prev_gray = 0;
        for (size_t i = 1; i < count; ++i) {
            const size_t gray = ToGrayCode(i);
            const size_t diff = gray ^ prev_gray;
            assert(diff != 0);
            const bs24 bs_diff(diff);
            const int  diff_pos = FindBit(bs_diff);
            assert(diff_pos >= 0);
            const auto pow = Ns[diff_pos];
            const bs24 bs_gray(gray);
            if (bs_gray.test(diff_pos)) {
                // move A <- B
                sum_a += pow;
                sum_b -= pow;
            }
            else {
                // move A -> B
                sum_a -= pow;
                sum_b += pow;
            }
            assert(sum_a >= 0);
            assert(sum_b >= 0);
            const auto diff_ab = abs(sum_a - sum_b);
            if (diff_min > diff_ab) {
                diff_min = diff_ab;
            }
            prev_gray = gray;
        }
        cout << diff_min << endl;
    }
    return 0;
}
