#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int idx[100001];
int in[100001];
int post[100001];

void preorder(int is, int ie, int ps, int pe) {
	int r, nr;
	if (is > ie || ps > pe)
		return;
	r = post[pe];
	cout << r << ' ';
	nr = idx[r] - is;
	preorder(is, idx[r]-1, ps, ps + nr-1);
	preorder(idx[r]+1, ie, ps + nr, pe-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}
	for (i=1;i<=N;i++) cin >> post[i];
	preorder(1, N, 1, N);
	cout << '\n';
	return 0;
}

