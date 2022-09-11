#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N;
int d_in[100001];
int d_post[100001];
int d_idx[100001];
void traverse(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int root = d_post[pe];
	cout << root << ' ';
	traverse(is, d_idx[root]-1, ps, ps+(d_idx[root]-is)-1);
	traverse(d_idx[root]+1, ie, ps+(d_idx[root]-is), pe-1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> d_in[i];
		d_idx[d_in[i]] = i;
	}
	for (i=0;i<N;i++)
		cin >> d_post[i];
	traverse(0, N-1, 0, N-1);
	cout << '\n';
	return 0;
}

