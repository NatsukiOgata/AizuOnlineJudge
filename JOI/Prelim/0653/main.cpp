#include <iostream>
#include <unordered_set>
#include <vector>

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
        T val;
        cin >> val;
        vec1.push_back(val);
    }
    return move(vec1);
}

int main()
{
    const int          N(cin2var<int>());
    const vec1<int>    X(cin2vec<int>(N));
    const int          M(cin2var<int>());
    const vec1<int>    A(cin2vec<int>(M));
    vector<int>        player_place;
    unordered_set<int> place;
    for (int x : X) {
        player_place.push_back(x);
        place.insert(x);
    }
    for (int a : A) {
        const int now  = player_place[a - 1];
        const int next = now + 1;
        if (next > 2019) {
            continue;
        }
        if (place.count(next)) {
            continue;
        }
        player_place[a - 1] = next;
        place.erase(now);
        place.insert(next);
    }
    for (int p : player_place) {
        cout << p << endl;
    }
    return 0;
}
