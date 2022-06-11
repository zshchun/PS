#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, ans;
int a[16];
bool is_promising(int n) {
	for (int i=0;i<n;i++) {
		if (a[n] == a[i] || abs(i-n) == abs(a[i]-a[n]))
			return false;
	}
	return true;
}
void solve(int n) {
	if (n == N) {
		ans++;
		return;
	}
	for (int i=0;i<N;i++) {
		a[n] = i;
		if (is_promising(n))
			solve(n+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	solve(0);
	cout << ans << '\n';
	return 0;
}
