#include <algorithm>
#include <iostream>
#include <vector>
#include "bfs.hpp"
#include "dfs.hpp"

using namespace std;

////////////////////////////////////////////////
 
void turn_std_sync_off() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
 
////////////////////////////////////////////////

int main(int argc, char** argv) {

    turn_std_sync_off();

    int32_t n, m; cin >> n >> m;
    graph<int32_t> g(n);

    vector<int8_t> vm(n);

    for (int32_t i = 0; i < m; ++i) {
        int32_t u, v; cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        vm[v] = 1;
    }

    vector<int32_t> st;
    for (int32_t i = 0; i < n; ++i) {
        if (vm[i] == 0)
            st.push_back(i);
    }

    vector<int32_t> p, r;
    dv s, e;

    for (int32_t s_ : st) {
        dv u = dfs(g, p, s_);
        if (e.second < u.second) {
            s.first = s_;
            e = u;
            r = p;
        }
    }

    vector<int32_t> path;

    for (int32_t i = s.first; i != e.first; i = r[i]) {
        path.push_back(i);
    }
    path.push_back(e.first);

    cout << path.size() << endl;

    for (auto i : path) {
        cout << i + 1<< " ";
    }
    cout << endl;

    return 0;
}