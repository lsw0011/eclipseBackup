//============================================================================
// Name        : melodious.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int n, m;
char vowels[6] = {"aeiou"};
char consonants[21] = { "bcdfghjklmnpqrstvwxz"};
string cur = "";


void drill(int n, int type){
	if(n == 0){
		cout << cur << endl;
		return;
	}else{
		if(type){
			for(int i = 0; i < 5; i++){
				cur.push_back(vowels[i]);
				drill(n-1, 1-type);
				cur.pop_back();
			}
		}else{
			for(int i = 0; i < 20; i++){
				cur.push_back(consonants[i]);
				drill(n-1, 1-type);
				cur.pop_back();
			}
		}
	}
}

int main() {
	cin >> n;
	m = n;
	drill(n, 1);
	drill(n, 0);
	return 0;
}
