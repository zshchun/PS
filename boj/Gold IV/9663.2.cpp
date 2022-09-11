#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, ans;
int d[15];

bool is_promising(int n) {
	for (int i=0;i<n;i++) {
		if (d[i] == d[n] || n - i == abs(d[n] - d[i]))
			return false;
	}
	return true;
}
void backtrack(int n) {
	if (n == N) {
		ans++;
		return;
	}
	for (int i=0;i<N;i++) {
		d[n] = i;
		if(is_promising(n)) {
			backtrack(n+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	backtrack(0);
	cout << ans << '\n';
	return 0;
}

