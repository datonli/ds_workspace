#include <iostream>
#include <vector>
using namespace std;

class Transform {
		public:
		    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
				for(int layer = 0;layer < n/2; layer ++){
					int first = layer;
					int last = n - 1 - layer ;
					for(int i  = first; i < last; i ++){
						int offset = i - first;
						int top = mat[first][i];
						mat[first][i] = mat[last - offset][first];
						mat[last - offset][first] = mat[last][last - offset];
						mat[last][last - offset] = mat[i][last];
						mat[i][last] = top;
					}
				}
				return mat;
			}
};

int main(){
	Transform t ;
	vector<vector<int> > mat;
	int cnt = 0;
	for(int i = 0; i < 3; i ++){
		vector<int> v ;
		for(int j = 0; j < 3; j ++)
		{
				cnt += 1;
				v.push_back(cnt);
		}
		mat.push_back(v);
		v.clear();
	}
	mat = t.transformImage(mat,3);
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 3; j ++){
			cout << mat[i][j] ;
		}
		cout << endl;
	}
	return 0;
}
