#include <iostream>
#include <vector>

using namespace std;


   void reOrderArray(vector<int> &array) {
        int len = array.size();
		for(int i = 1; i < len; i ++){
			if(array[i] % 2 == 1){
				for(int j = i; j > 0 ; j --){
					if(array[j-1] % 2 == 0){
						int tmp = array[j-1]; 
						array[j-1] = array[j];
						array[j] = tmp;
					}
				}
			}
		}
    }

int main(){
	vector<int> array ;
	for(int i = 1; i <= 7; i ++)
		array.push_back(i);
	reOrderArray(array);
	for(int i = 0; i < array.size(); i ++)
		cout << array[i] << ",";
	cout << endl;
	return 1;
}
