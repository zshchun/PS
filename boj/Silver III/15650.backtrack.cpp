#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int digit[9];
bool used[9];
int N, M;

void backtrack(int n, int d) {
	int i;
	if (n == M) {
		for (i=0;i<M;i++) {
			cout << digit[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (i=d;i<=N;i++) {
		if (!used[i]) {
			used[i] = 1;
			digit[n] = i;
			backtrack(n+1, i+1);
			used[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	backtrack(0, 1);
	return 0;
}

