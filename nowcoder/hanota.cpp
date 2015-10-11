#include <iostream>
using namespace std;

void hanota(int n,char A,char B,char C){
	if(n == 1)
			cout << "from " << A << " to " << C << endl;
	else{
		hanota(n-1,A,C,B);
		cout << "from " << A << " to " << C << endl;
		hanota(n-1,B,A,C);
	}
}

int main(){
	int n = 3;
	char A = 'A',B = 'B',C = 'C';
	hanota(n,A,B,C);
	return 0;
}
