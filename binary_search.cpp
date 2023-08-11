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