vector<int> fenwick(n + 1, 0);
auto sum = [&](int i) -> int {
    int ret = 0;
    while (i) {
        ret += fenwick[i];
        i -= (i & -i);
    }
    return ret;
};
auto update = [&](int i, int diff) {
    while (i <= n) {
        fenwick[i] += diff;
        i += (i & -i);
    }
};

// (i & -i) -> LSB
// diff 값 미리 계산 필수