#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, s1, s2;
	int c, d;
	int j[3];
	string a;
	cin>>t;
	while (t--) {
		cin >> a;
		memset(j, 0, sizeof(j));
		c = a[0]-'A';
		d = a[a.size()-1]-'A';
		j[c] = 1;
		j[d] = -1;
		if (c == d) {
			cout << "NO\n";
			continue;
		}
		s1 = 0;
		s2 = 0;
		for (i=0;i<a.size();i++) {
			c = a[i]-'A';
//			cout << c << ":"<<j[c] <<"\n";
			if (!j[c]) {
				s1 --;
				s2 ++;
			} else {
				s1 += j[c];
				s2 += j[c];
			}
			if (s1 < 0) s1 = -99999999;
			if (s2 < 0) s2 = -99999999;
		}
		if (s1 == 0 || s2 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
//		cout << a << a.size()<<"\n";
	}
	return 0;
}
