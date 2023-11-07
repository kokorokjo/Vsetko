#include <bits/stdc++.h>
using namespace std;
#define pn 1000000007


int main() {
	
	int n; cin >> n;
	deque <int> A(n);
	int k = 0;
	for (int i = 0; i < n; i++) { // O(n)
		cin >> A[i];
		if (A[i] == 1) k++;
	}
	
	if (k == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	if (k == n) { // out = n!
		uint64_t out = 1;
		for (int i = 2; i <= n; i++) out = out * i % pn;
		cout << out << endl;
		return 0;
	}
	
	while (A.front() != 1 || A.front() == A.back()) {
		A.push_front(A.back());
		A.pop_back();
	}
	A.shrink_to_fit();
	
	bool possible = true;
	vector <bool> notInA(n+1, true);
	for (int i = 1; i < n; i++) { // O(n)
		if (A[i-1] != A[i] && !notInA[A[i]]) possible = false;
		notInA[A[i]] = false;
	}
	if (!possible) {
		cout << 0 << endl;
		return 0;
	}
	
	deque <array <int, 3>> u;   // {num, left, right}
	deque <int> mxw;            // max window {pos}
	vector <int> l(n, 1); // lower bounds
	vector <int> lc(n+1);    // lc[i] - count of numbers not in A and at least i
	lc[n] = notInA[n];
	u.push_front({A.back(), n-k, n-1});
	for (int i = n-1; i >= 1; i--) {                                    // O(n)
		while (!mxw.empty() && A[mxw.front()] <= A[i]) mxw.pop_front(); // O(1)
		mxw.push_front(i);
		if (mxw.back() == i+k) mxw.pop_back();
		l[i] = A[mxw.back()];
		
		if (A[i-1] != A[i]) {
			u.front()[2] = min(u.front()[2], i);
			if (A[i-1] < A[i]) {
				u.push_front({A[i-1], i-k, i-k});
			} else if (A[i-1] > A[i]) {
				u.front()[1] = max(u.front()[1], i);
				u.push_front({A[i-1], i-k, i-1});
			}
			if (u.front()[1] > u.front()[2]) {
				cout << 0 << endl;
				return 0;
			}
		}
		
		lc[i] = lc[i+1] + notInA[i];
	}
	
	/*
	for (int i = 0; i < n; i++) cout << A[i] << ' ';
	cout << endl;
	for (int i = 0, j = 0; i < n; i++) {
		if (j < u.size() && i >= u[j][1]) {
			cout << u[j][0] << ' ';
			cout.flush();
		} else {
			cout << "  ";
		}
		if (i == u[j][2]) j++;
	}
	cout << endl;
	for (int i = 0; i < n; i++) cout << l[i] << ' ';
	cout << endl;
	*/
//	for (auto i : u) cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
	
	uint64_t out = 1;
	vector <int> countSort(n+1, 0);
	for (int i = 0, j = 0; i < n; i++) {// |u[i]| < 0 - not possible
//		if (i == u[j][2]) out = out * max(0, u[j][2]-u[j][1]+1) % pn, j++;
		if (i == u[j][2]) {
			if (j < (int)u.size()) out = out * max(0, u[j][2]-u[j][1]+1) % pn, j++;
		} else countSort[lc[l[i]]]++;
	}
//	for (int i = 0; i < n+1; i++) cout << i << ' ' << lc[i] << ' ' << countSort[i] << endl;
	for (int i = 0, removed = 0; i < (int)countSort.size() && out; i++) { // O(n - |u|)
		while (countSort[i]) {
			out = out * (i-removed) % pn;
			countSort[i]--, removed++;
		}
	}
	
	cout << out << endl;
	
	return 0;
}