#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100001];
int o[100001] = {0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, n, i, f=1, p, j;
	cin>>t;
	while(t--) {
		cin>>n;
		for (i=1;i<=n;i++) {
			cin>>a[i];
			o[a[i]] = i;
		}
		p = n;
		for (i=n;i>0;i--) {
			if (o[i] <= p) {
				for (j=o[i];j<=p;j++) {
					if (!a[j]) continue;
					if (f) f = 0;
					else cout << " ";
					cout << a[j];
					a[j] = 0;
				}
				p = o[i]-1;
			}
		}
		cout << "\n";
	}

	return 0;
}
