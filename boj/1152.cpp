#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char a[1000001];
	int m = 0, i = 0;
	char *c = a;
	cin.getline(c, 1000000);
	do {
		while (*c && *c != ' ') {
			m = 1;
			c++;
		}
		if (m) { 
			i++;
			m = 0;
		}
	} while (*c++);
	cout << i << "\n";
	return 0;
}

