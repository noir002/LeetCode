class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * node + 1, l, mid);
            build(arr, 2 * node + 2, mid + 1, r);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int index, int value, int node, int l, int r) {
        if (l == r) {
            tree[node] = value;
        } else {
            int mid = (l + r) / 2;
            if (index <= mid)
                update(index, value, 2 * node + 1, l, mid);
            else
                update(index, value, 2 * node + 2, mid + 1, r);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int fruitSize, int node, int l, int r) {
        if (tree[node] < fruitSize)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int leftResult = query(fruitSize, 2 * node + 1, l, mid);
        if (leftResult != -1)
            return leftResult;
        return query(fruitSize, 2 * node + 2, mid + 1, r);
    }

    int findBasket(int fruitSize) {
        return query(fruitSize, 0, 0, n - 1);
    }

    void markUsed(int index) {
        update(index, 0, 0, 0, n - 1);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree seg(baskets);
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            int idx = seg.findBasket(fruits[i]);
            if (idx == -1) {
                unplaced++;
            } else {
                seg.markUsed(idx);
            }
        }

        return unplaced;
    }
};
