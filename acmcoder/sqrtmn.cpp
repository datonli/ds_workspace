#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	float m,n;
	float sum=0.0;
	while(cin>>n>>m){
		while(m--){
			sum+=n;
			n = sqrt(n);
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
