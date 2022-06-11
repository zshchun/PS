#include <bits/stdc++.h>
using namespace std;

int main() {
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const char *ss[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int m, d, s, i;
	cin >> m >> d;
	s = 0;
	for (i=0;i<(m-1);i++)
		s += mon[i];
	s = s + d - 1;
	cout << ss[s % 7] << "\n";
	
	return 0;
}
