#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, M;
int a[9];
int num[9];
bool used[9];

void backtrack(int c, int n) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (i=n;i<=N;i++) {
		if (used[i]) continue;
		if (num[i-1] == prev) continue;
		used[i] = 1;
		a[c] = num[i-1];
		prev = num[i-1];
		backtrack(c+1, n);
		used[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N >> M;
	for (i=0;i<N;i++)
		cin >> num[i];
	sort(num, num+N);
	backtrack(0, 1);
	return 0;
}

