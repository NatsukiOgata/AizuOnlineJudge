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

struct Team
{
    int id;
    int group;
    int answer;
    int penalty;
};

int main()
{
    vec1<Team>              teams;
    vec1<Team>              winner;
    unordered_map<int, int> map_group_wins;
    while (true) {
        const auto N(cin2var<int>());
        if (!N) break;
        teams.clear();
        map_group_wins.clear();
        for (int i = 0; i < N; ++i) {
            const auto Ns(cin2vec<int>(4));
            auto       ite(Ns.cbegin());
            Team       team{};
            team.id      = *ite++;
            team.group   = *ite++;
            team.answer  = *ite++;
            team.penalty = *ite++;
            teams.push_back(move(team));
        }
        sort(teams.begin(), teams.end(), [](const Team& l, const Team& r) {
            if (l.answer < r.answer) return false;
            if (l.answer > r.answer) return true;
            if (l.penalty < r.penalty) return true;
            if (l.penalty > r.penalty) return false;
            return l.id < r.id;
        });
        for (auto ite(teams.begin()); ite != teams.end(); /*++ite*/) {
            const auto& team(*ite);
            const bool  is_win = [&] {
                const auto group_wins(map_group_wins[team.group]);
                if (winner.size() < 10 && group_wins < 3) {
                    return true;
                }
                if (winner.size() < 20 && group_wins < 2) {
                    return true;
                }
                if (winner.size() < 26 && group_wins == 0) {
                    return true;
                }
                return false;
            }();
            if (is_win) {
                cout << team.id << endl;
                ++map_group_wins[team.group];
                winner.push_back(team);
                ite = teams.erase(ite);
            }
            else {
                ++ite;
            }
        }
    }
    return 0;
}
