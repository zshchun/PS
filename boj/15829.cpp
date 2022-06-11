#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, h=0, q=1, M=1234567891;
	char s[51];
	cin >> n;
	cin >> s;
	for (i=0;i<n;i++) {
		h = (h + (q * (s[i] - 'a'+1))) % M;
		q = (q * 31) % M;
	}
	cout << h << "\n";
	return 0;
}
