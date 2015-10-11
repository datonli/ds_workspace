#include <iostream>
#include <vector>

using namespace std;

vector<int> fib(int n){
	vector<int> a(n+1);
	a[0] = 1;
	a[1] = 1;
	for(int i = 2; i < n+1; i ++){
		a[i] = a[i-1] + a[i-2];
	}
	return a;
}

void lcs(vector<int> a,vector<int> f,vector<vector<int> >c)
{
	c = new 
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int i = 0;
	while(n--){
		cin >> a[i++];
	}
	vector<int> f = fib(n);
	
	return 0;
}
