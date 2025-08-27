#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n;
string s;
bool visited[101];

void dfs(int l, int r) {
	if (l > r) return;

	int m = l;
	for (int i=l;i<=r;i++)
		if (s[i] < s[m])
			m = i;
	
	visited[m] = 1;
	for (int i=0;i<n;i++)
		if (visited[i])
			cout << s[i];
	cout << endl;

	dfs(m+1, r);
	dfs(l, m-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();

	dfs(0, n-1);

	return 0;
}
