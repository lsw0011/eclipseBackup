//============================================================================
// Name        : twoRobots.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int queries[1000][2];

int maxq;

int brain(int q, int r, int r1p, int r2p, int d){
	int* query = &queries[q - 1][0];
	if (r == 1 && r1p == 0){
		r1p = *(query);
	}
	if (r == 2 && r2p == 0){
		r2p = *(query);
	}

	if(r == 1){
		int distance = abs(r1p - *(query));
		distance += abs(*(query) - *(query + 1));
		r1p = *(query + 1);
		cout << q <<  " " << r << " " << r1p << " " << r2p << " " << d + distance << endl;
		if(q != maxq){
			int d1 = brain(q + 1, 1, r1p, r2p, distance + d);
			int d2 = brain(q + 1, 2, r1p, r2p, distance + d);
			return distance + min(d1, d2);
		}
		return distance;
	}
	if(r == 2){
		int distance = abs(r2p - *query);
		distance += abs(*query - *(query + 1));
		r2p = *(query + 1);
		if(q != maxq){
			int d1 = brain(q + 1, 1, r1p, r2p, distance);
			int d2 = brain(q + 1, 2, r1p, r2p, distance);
			return distance + min(d1, d2);
		}
		return distance;
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int m;
		int l1, l2;
		cin >> m >> maxq;
		for(int j = 0; j < maxq; j++){
			cin >> l1 >> l2;
			queries[j][0] = l1;
			queries[j][1] = l2;
		}
		cout << brain(1, 1, 0, 0, 0) << endl;
	}
	return 0;
}
