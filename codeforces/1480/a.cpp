#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, k;
	char c;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		for (i=0;i<s.size();i++) {
			c = s[i]-'a';
			if ((i % 2) == 0) {
				for (j=0;j<26 && c==j;j++) { ; }
			} else {
				for (j=25;j>=0 && c==j;j--) { ; }
			}
			c = j+'a';
			cout << c;
		}
		cout <<'\n';
	}
	return 0;
}
