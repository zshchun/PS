#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[256];
int b[256];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans, i = 1, j;
	string s, t;
	while (1) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		ans = true;
		cin >> s >> t;
		if (s == "END" && t == "END") break;
		for (char &c : s)
			a[c]++;
		for (char &c : t)
			b[c]++;
		for (j=0;j<256;j++)
			if (a[j] != b[j])
				ans = false;
		if (ans)
			cout << "Case " << i << ": same\n";
		else
			cout << "Case " << i << ": different\n";
		i++;
	}
	return 0;
}
