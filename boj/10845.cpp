#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, b, e;
	int q[MAX];
	cin>>t;
	string s;
	b = 0;
	e = 0;
	while(t--) {
		cin >> s;
		if (s == "push") {
			cin >> q[e++];
			if (e == MAX)
				e = 0;
		} else if (s == "front") {
			if (b == e)
				cout << "-1\n";
			else
				cout << q[b] << '\n';
		} else if (s == "back") {
			if (b == e)
				cout << "-1\n";
			else
				cout << q[e-1] << "\n";
		} else if (s == "size") {
			if (b <= e)
				cout << e-b << "\n";
			else
				cout << MAX+e-b << "\n";
		} else if (s == "empty") {
			if (b == e)
				cout << "1\n";
			else
				cout << "0\n";
		} else if (s == "pop") {
			if (b == e)
				cout << "-1\n";
			else {
				cout << q[b++] << "\n";
				if (b == MAX)
					b = 0;
			}
		}
	}

	return 0;
}

