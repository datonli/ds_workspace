#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Clearer {
		public:
		    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
				vector<int> row(n,0),col(n,0);
				for(int i = 0; i < n; i ++)
						for(int j = 0; j < n ; j ++){
							if(mat[i][j] == 0){
									row[i] = 1;
									col[j] = 1;
							}
						}

				for(int i = 0; i < n; i ++)
						for(int j = 0; j < n ; j ++){
							if(row[i] || col[j]){
									mat[i][j] = 0;
							}
						}
				return mat;
		    }
};


int main(){
	Clearer c;
	vector<vector<int> > mat;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	mat.push_back(v);
	v.clear();
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	mat.push_back(v);
	v.clear();
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	mat.push_back(v);
	for(int i = 0 ; i < 3; i ++){
			for(int j = 0; j < 3; j ++)
					cout << mat[i][j] << " ";
			cout << endl;
	}
	mat = c.clearZero(mat,3);
	for(int i = 0 ; i < 3; i ++){
			for(int j = 0; j < 3; j ++)
					cout << mat[i][j] << " ";
			cout << endl;
	}
	return 0;
}
