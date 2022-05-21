#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[27];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N;
	cin >> T;
	string s;
	while(T--) {
		memset(a, 0, sizeof(a));
		cin >> N >> s;
		for (i=0;i<N;i++) {
			while (i+1 < N && s[i] == s[i+1]) { i++; };
			if (a[s[i]-'A']) break;
			a[s[i]-'A'] = 1;
		}
		if (i == N)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
