#include <bits/stdc++.h>

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int now) {
        if (parent[now] == now) return now;
        return parent[now] = find(parent[now]);
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};