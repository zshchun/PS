#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

char c[36];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, b, i;
	cin >> n >> b;
	string ans;
	for (i=0;i<10;i++)
		c[i] = i + '0';
	for (i=0;i<26;i++)
		c[i+10] = i + 'A';
	while (n) {
		ans += c[n % b];
		n /= b;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
