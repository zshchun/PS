#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N, M;
int num[9];
int a[9];
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
		a[c] = num[i-1];
		backtrack(c+1, i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int i;
	for (i=0;i<N;i++)
		cin >> num[i];
	sort(num, num+N);
	N = unique(num, num+N) - num;
	backtrack(0, 1);
	return 0;
}

