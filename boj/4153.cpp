#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	int a[3];
	for (i=0;i<3;i++)
		a[i] = 1.0;

	while (1) {
		for (i=0;i<3;i++) cin >> a[i];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
			return 0;
		for (i=0;i<3;i++) {
			if (a[i]*a[i]+ a[(i+1)%3]*a[(i+1)%3] == a[(i+2)%3]*a[(i+2)%3])
				break;
		}
		if (a[i]*a[i]+ a[(i+1)%3]*a[(i+1)%3] == a[(i+2)%3]*a[(i+2)%3])
			cout << "right\n";
		else
			cout << "wrong\n";

	}
	return 0;
}
