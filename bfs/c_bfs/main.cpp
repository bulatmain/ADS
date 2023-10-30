#include <iostream>
#include <vector>
#include "bfs.hpp"

using namespace std;

int main(int argc, char** argv) {

    int32_t n, m; cin >> n >> m;
    graph<int32_t> g(n);

    for (int32_t i = 0; i < m; ++i) {
        int32_t u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int32_t> d, p;

    bfs(g, d, p, 0);


    cout << "Distance:\n";
    for (int32_t i = 0; i < n; ++i) {
        cout << i << " ";
    }
    cout << "\n";
    for (int32_t i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << "\n";


    int32_t u = 4;
    vector<int32_t> path;
    do {
        path.push_back(u);
        u = p[u];
    } while (p[u] != u);


    for (auto u : path) 
        if (u != 0)
            cout << u << " -> ";
    cout << 0 << "\n";
    
    return 0;
}