#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 1;
vector<int> adj[MAX_N];
vector<int> vec;
bool vis[MAX_N];
int first[MAX_N], last[MAX_N];

void dfs(int u, int& node) {
	vis[u] = true;
	first[u] = node;
	node++;
	vec.push_back(u);
	for (int& v : adj[u]) {
		if (!vis[v]) {
			dfs(v, node);
		}
	}
	last[u] = node;
}

void test_case(int& tc) {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		adj[p-1].push_back(i);
	}

	int node = 0;
	dfs(0, node);

	// for (int u = 0; u < n; u++) {
	// 	if (first[u] != last[u]) {
	// 		cout << "subtree of node " << u + 1 << " = ";
	// 		for (int i = first[u]; i < last[u]; i++) {
	// 			cout << vec[i] + 1 << " ";
	// 		}
	// 		cout << "\n";
	// 	}
	// }
	// cout << "\n";

	for (int i = 0; i < q; i++) {
		int u, k;
		cin >> u >> k;
		--u; --k;
		if (first[u] + k < last[u]) {
			cout << vec[first[u]+k] + 1;
		} else {
			cout << -1;
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
