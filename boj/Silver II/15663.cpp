#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, M;
int a[9];
int num[9];
int cnt[10001];

void backtrack(int c, int n) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (i=n;i<=N;i++) {
		if (cnt[num[i-1]] <= 0) continue;
		cnt[num[i-1]]--;
		a[c] = num[i-1];
		backtrack(c+1, n);
		cnt[num[i-1]]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		cin >> num[i];
		cnt[num[i]]++;
	}
	sort(num, num+N);
	N = unique(num, num+N) - num;
	backtrack(0, 1);
	return 0;
}

