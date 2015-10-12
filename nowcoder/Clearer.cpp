#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Clearer {
		public:
		    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
				vector<int> row,col;
				for(int i = 0; i < n; i ++)
						for(int j = 0; j < n ; j ++){
							if(mat[i][j] == 0){
								row.push_back(i);
								col.push_back(j);
							}
						}
				sort(row.begin(),row.end());
				sort(col.begin(),col.end());
				cout << "begin : " ;
				for(int i = 0; i < row.size(); i ++) cout << row[i] << " ";
				cout << endl;
				for(int i = 0; i < col.size(); i ++) cout << col[i] << " ";
				cout << endl;
				vector<int>::iterator it = unique(row.begin(),row.end());
				row.erase(it,row.end());
				it = unique(col.begin(),col.end());
				col.erase(it,col.end());
				cout << "after: " ;
				for(int i = 0; i < row.size(); i ++) cout << row[i] << " ";
				cout << endl;
				for(int i = 0; i < col.size(); i ++) cout << col[i] << " ";
				cout << endl;
				for(int i = 0; i < row.size(); i ++)
						for(int j = 0 ; j < n;j ++){
							mat[row[i]][j] = 0;
						}
				for(int i = 0; i < n; i ++)
						for(int j = 0 ; j < col.size();j ++){
							mat[i][col[j]] = 0;
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
