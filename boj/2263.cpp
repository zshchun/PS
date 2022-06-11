#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N;
int d_in[100001];
int d_post[100001];
int idx[100001];
void preorder(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e) return;
	int r = d_post[post_e];
	cout << r << ' ';
	preorder(in_s, idx[r]-1, post_s, post_s + (idx[r]-in_s)-1);
	preorder(idx[r]+1, in_e, post_s + (idx[r]-in_s), post_e-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> d_in[i];
		idx[d_in[i]] = i;
	}
	for (i=1;i<=N;i++)
		cin >> d_post[i];
	preorder(1, N, 1, N);
	cout << '\n';
	return 0;
}


