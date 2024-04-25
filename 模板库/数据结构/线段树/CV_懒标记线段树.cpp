#include "bits/stdc++.h"

using namespace std;


// arr和区间，索引都从0开始

class SegmentTree {

public:

    SegmentTree(vector<int> & arr) {
        int n = arr.size();
        ori_len = n;

        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        build(1, 0, n - 1, arr);

    }

    // 构建线段树
    void build(int ti, int l, int r, vector<int> & arr) {

        if (l == r) {
            tree[ti] = arr[l];
            return;
        }

        int left_chil = ti << 1;
        int right_chil = (ti << 1) + 1;
        int mid = (r - l) / 2 + l;

        build(left_chil, l, mid, arr);
        build(right_chil, mid + 1, r, arr);

        tree[ti] = tree[left_chil] + tree[right_chil];
    }

    void _update(int ti, int tl, int tr, int l, int r, int val) {
        if (l <= tl && tr <= r) {
            tree[ti] += (tr - tl + 1) * val;
            lazy[ti] += val;
            return;
        }

        if (r < tl || l > tr)
            return ;


        int mid = tl + ((tr - tl) >> 1);
        int lti = ti * 2;
        int rti = ti * 2 + 1;

        // 更新并下传懒标记
        lazy_down(ti, tl, tr);

        if (l <= mid) {
            _update(lti, tl, mid, l, min(r, mid), val);
        }
        if (mid <= r) {
            _update(rti, mid + 1, tr, max(mid, l), r, val);
        }
        tree[ti] = tree[lti] + tree[rti];
    }
    // 给[l, r]加上val
    void update(int l, int r, int val) {
        _update(1, 0, ori_len - 1, l, r, val) ;
    }

    int _query(int ti, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r)
            return tree[ti];

        if (r < tl || l > tr)
            return 0;

        int mid = tl + ((tr - tl) >> 1);
        int lti = ti * 2;
        int rti = ti * 2 + 1;

        // 更新并下传懒标记
        lazy_down(ti, tl, tr);

        int sum = 0;

        if (l <= mid)
            sum = _query(lti, tl, mid, l, min(mid, r));
        if (mid <= r)
            sum += _query(rti, mid + 1, tr, max(l, mid + 1), r);

        return sum;
    }

    int query(int l, int r) {
        return _query(1, 0, ori_len - 1, l, r);
    }

    inline void lazy_down(int ti, int tl, int tr) {
        int lti = ti * 2;
        int rti = ti * 2 + 1;
        int mid = tl + ((tr - tl) >> 1);

        if (lazy[ti] && tl != tr) {
            tree[lti] += lazy[ti] * (mid - tl + 1);
            tree[rti] += lazy[ti] * (tr - mid);

            lazy[lti] += lazy[ti];
            lazy[rti] += lazy[ti];

            lazy[ti] = 0;
        }
    }



private:
    vector<int> tree;
    vector<int> lazy;
    int ori_len;
};
