#include <iostream>

using namespace std;

int josephus_re(int n,int k){
	return n==0?0:(josephus_re(n-1,k)+k)%n;
}

int josephus(int n,int k){
	int s = 0;
	for(int i = 2; i <= n; i ++)
			s = (s + k)%i;
	return s;
}
