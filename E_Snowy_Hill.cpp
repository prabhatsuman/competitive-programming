#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Segment tree node
struct Node {
    int sum;
    int minIndex;
};

// Builds the segment tree
void build(vector<int>& snow, vector<Node>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = { snow[start], start };
    } else {
        int mid = (start + end) / 2;
        build(snow, tree, 2*node, start, mid);
        build(snow, tree, 2*node+1, mid+1, end);

        if (tree[2*node].sum < tree[2*node+1].sum) {
            tree[node] = tree[2*node];
        } else {
            tree[node] = tree[2*node+1];
        }
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
}

// Queries the segment tree for the smallest interval with sum K
Node query(vector<Node>& tree, int node, int start, int end, int K) {
    if (start == end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    Node left = tree[2*node];
    Node right = tree[2*node+1];

    if (left.sum >= K) {
        return query(tree, 2*node, start, mid, K);
    } else {
        Node result = query(tree, 2*node+1, mid+1, end, K-left.sum);
        result.sum += left.sum;
        if (left.minIndex < result.minIndex) {
            result.minIndex = left.minIndex;
        }
        return result;
    }
}

// Finds the smallest interval with sum K
pair<int, int> findSmallestInterval(vector<int>& snow, vector<Node>& tree, int K) {
    Node result = query(tree, 1, 0, snow.size()-1, K);
    return make_pair(result.minIndex, result.minIndex + 1);
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> snow(N);
    for (int i = 0; i < N; i++) {
        cin >> snow[i];
    }

    // Build the segment tree
    int treeSize = 2 * pow(2, ceil(log2(N))) - 1;
    vector<Node> tree(treeSize);
    build(snow, tree, 1, 0, N-1);

    // Process the queries
    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        pair<int, int> interval = findSmallestInterval(snow, tree, K);
        cout << interval.first << " " << interval.second << endl;
    }

    return 0;
}
