#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int> > retote(vector<vector<int> > a,int k,int j,int N){
		if(N==1) return a;
		int layer;
        for(layer=k; layer<(j+N)/2; layer++){
			int first = layer;
			int last = j+N-1-layer;
			int i;
			for(i=layer; i<last; i++){
				int offset = i-layer;
				char top = a[first][i];
				a[first][i] = a[last-offset][first];
				a[last-offset][first] = a[last][last-offset];
				a[last][last-offset] = a[i][last];
				a[i][last] = top;
			}
		}
		return a;
}



vector<vector<int> > even(vector<vector<int> > a,int i,int j,int N){
	a = retote(a,i,j,N);
	if(N%2 == 0) {
		a = even(a,i,j,N/2);
		a = even(a,i+N/2,j,N/2);
		a = even(a,i+N/2,j+N/2,N/2);
		a = even(a,i,j+N/2,N/2);
		//a = retote(a,i,j,N/2);
		//a = retote(a,i+N/2,j,N/2);
		//a = retote(a,i+N/2,j+N/2,N/2);
		//a = retote(a,i,j+N/2,N/2);
	}
	return a;
}

bool judge(vector<vector<int> > a,vector<vector<int> > b,int n){
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
	{
		if(a[i][j] != b[i][j]) return false;
	}
	return true;
}

int main(){
	freopen("ie.txt","r",stdin);
	int m,n;
	cin >> m;
	while(m--){
	cin >> n;
	vector<vector<int> > a(n,vector<int>(n));
	vector<vector<int> > b(n,vector<int>(n));
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
        cin >> a[i][j];
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
        cin >> b[i][j];
	//a = retote(a,0,0,n);	
	a = even(a,0,0,n);	
	for (int i=0;i<n;i++){
	for (int j=0;j<n;j++)
        cout << a[i][j]<< " ";
	cout << endl;
	}
	if(judge(a,b,n)) cout << "Yes" << endl;
	else cout << "No" << endl;
	}
	return 0;
}
