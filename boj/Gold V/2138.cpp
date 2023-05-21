#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll N, ans;
int m[100002];
int goal[100002];
void backtrack(int i, int count) {
	if (i > N) {
		if (m[i-1] == goal[i-1] && count < ans)
			ans = count;
		return;
	}
	if (i == 1 || m[i-1] == goal[i-1])
		backtrack(i+1, count);

	m[i-1] = !m[i-1];
	m[i] = !m[i];
	m[i+1] = !m[i+1];
	if (i == 1 || m[i-1] == goal[i-1])
		backtrack(i+1, count+1);

	m[i-1] = !m[i-1];
	m[i] = !m[i];
	m[i+1] = !m[i+1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	char c;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> c;
		m[i] = c - '0';
	}
	for (i=1;i<=N;i++) {
		cin >> c;
		goal[i] = c - '0';
	}
	ans = INF;

	backtrack(1, 0);
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;

	return 0;
}
