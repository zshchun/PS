#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j, t, a, d, found;
	int mx;
	cin >> n;
	while(n--) {
		cin>>t>>d;
		while(t--) {
			cin >> a;
			mx = 10*d;
			if (a > mx) {
				cout << "YES\n";
				continue;
			} else {
				found = 0;
				for (i=0;i*10+d<=mx && i*10+d<=a;i++) {
					if ((a-i*10+d) % d == 0) {
						found = 1;
						break;
					}
				}
				if (found)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}
