
#pragma GCC diagnostic ignored "-Wunused-result"

#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h>

//constants
const int CHUNK = 10*1000*1000;
const int CHUNK_FIRST = 2222222;
const int CHUNK_LAST = 7777777;
const int LAST_BEFORE_CHUNK = 777777;
const long long MAX = 1e15;

inline bool hasOnlyPrimeDigits(long long n){
	while(n > 0){
		char d = n % 10;
		if (d != 2 && d != 3 && d != 5 && d != 7){
			return false;
		}
		n /= 10;
	}
	return true;
}

std::vector<int> getPrimesTill(int max){
	std::vector<int> primes;
	std::vector<bool> isPrime(max + 1, true);
	isPrime[0] = 0;
	isPrime[1] = 0;

	for(int i = 2; i * i <= max; i++){
		if(isPrime[i]){
			for(int j = i; j * i <= max; j += 1){
				isPrime[i*j] = 0;
			}
		}
	}
	for(int i = 0; i <= isPrime.size(); i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	return primes;
}

int countMegaPrimes(long long first, long long last){
	if(first > last){
		return 0;
	}
	static std::vector<int> primes = getPrimesTill(sqrt(MAX));
	std::vector<bool> isPrime(last-first + 1, true);

	for(int p: primes){
		if((long long)p * p > last){
			break;
		}
		long long from = std::max(1LL * p , (first + p - 1) / p) * p;
		for(int i = from - first; i <= last - first; i += p){
			isPrime[i] = 0;
		}
	}
	int count = 0;
	for(int i = 0; i < isPrime.size(); i++){
		if(isPrime[i] && hasOnlyPrimeDigits(first + i)){
			count++;
		}
	}
	return count;
}

int main() {
	long long first, last;
	scanf("%lld %lld", &first, &last);
	int count;
	if(last <= LAST_BEFORE_CHUNK){
		count = countMegaPrimes(first, last);
	}else{
		if(first <= LAST_BEFORE_CHUNK){
			count = countMegaPrimes(first, LAST_BEFORE_CHUNK);
			first = LAST_BEFORE_CHUNK + 1;
		}
		for(long long firstPart = first / CHUNK * CHUNK + CHUNK_FIRST; firstPart <= last; firstPart += CHUNK){
			if(hasOnlyPrimeDigits(firstPart)){
				long long lastPart = firstPart / CHUNK * CHUNK + CHUNK_LAST;
				count += countMegaPrimes(std::max(first, firstPart), std::min(last, lastPart));
			}
		}
	}
	printf("%d", count);
}
