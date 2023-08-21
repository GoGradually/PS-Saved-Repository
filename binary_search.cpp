#include <bits/stdc++.h>

int last_true(int lo, int hi) {
    lo--;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int first_true(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int binary_search(int lo, int hi) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return hi;
}
int ternary_search(int lo, int hi) {
    ll lo = 0, hi = n - 1;
    while (hi - lo >= 3) {
        ll p = (lo * 2 + hi) / 3, q = (lo + hi * 2) / 3;
        if (f(p) >= f(q))
            hi = q;
        else
            lo = p;
    }
    int val = 0;
    int mx = 0;
    for (int i = lo; i <= hi; i++) {
        int temp = f(i);
        if (mx < temp) {
            mx = temp;
            val = i;
        }
    }
    return val;
}