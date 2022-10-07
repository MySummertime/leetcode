#include <unordered_map>

using std::unordered_map;

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
class MyCalendarThree {
public:
    // segment tree
    MyCalendarThree() {}

    int book(int start, int end) {
        update(start, end - 1, 0, SCALE, 1);
        return tree[1];
    }

private:
    void update(int start, int end, int l, int r, int cur_node) {
        if (l > end || r < start)   return;
        else if (start <= l && r <= end) {
            ++tree[cur_node];
            ++flag[cur_node];
        }
        else {
            int lchild = 2 * cur_node, rchild = lchild + 1;
            int m = l + ((r - l) >> 1);
            update(start, end, l, m, lchild);
            update(start, end, m + 1, r, rchild);
            tree[cur_node] = flag[cur_node] + std::max(tree[lchild], tree[rchild]);
        }
    }

private:
    unordered_map<int, int> tree;
    unordered_map<int, int> flag;
    static constexpr int SCALE = 1e9;
};
