#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N;
	cin >> T;
	while(T--) {
		cin >> N;
		int s=0;
		cin >> a[0];
		cin >> a[1];
		for (i=2;i<N;i++) {
			cin >> a[i];
			if (s) continue;
			if (a[i-1] != a[i] && a[i-1] == a[i-2])
				s = i+1;
			else if (a[i-1] != a[i] && a[i-2] == a[i])
				s = i;
			else if (a[i-1] == a[i] && a[i-2] != a[i-1])
				s = i-1;
		}
		cout << s << '\n';
	}
	return 0;
}
