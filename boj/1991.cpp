#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct tree_t {
	int left_child;
	int right_child;
};
vector<tree_t> t(26);
enum traverse_type { PRE, IN, POST };
void traverse(int n, traverse_type tt) {
	if (tt == PRE) cout << (char)(n + 'A');
	if (t[n].left_child) traverse(t[n].left_child, tt);
	if (tt == IN) cout << (char)(n + 'A');
	if (t[n].right_child) traverse(t[n].right_child, tt);
	if (tt == POST) cout << (char)(n + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i;
	char p, l, r;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> p >> l >> r;
		if (l != '.') t[p-'A'].left_child = l - 'A';
		if (r != '.') t[p-'A'].right_child = r - 'A';
	}
	traverse(0, PRE);
	cout << '\n';
	traverse(0, IN);
	cout << '\n';
	traverse(0, POST);
	cout << '\n';
	return 0;
}

