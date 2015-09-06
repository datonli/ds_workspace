class Solution {
		public:
		    int GetUglyNumber_Solution(int index) {
				if(index <= 0) return 0;
				int* arr = new int[index];
				arr[0] = 1;
				arr[1] = 2;
				arr[2] = 3;
				arr[3] = 4;
				arr[4] = 5;
				for(int i = 5 ;i < index; i ++){
					int min2 = 0, min3 = 0, min5 = 0;
					int tmp = 0;
					for(int j = 0; j < i; j ++){
						tmp = arr[j]*2;
						if(tmp > arr[i-1]) {
							min2 = tmp;
							break;
						}
					}
					for(int j = 0; j < i; j ++){
						tmp = arr[j]*3;
						if(tmp > arr[i-1]) {
							min3 = tmp;
							break;
						}
					}
					for(int j = 0; j < i; j ++){
						tmp = arr[j]*5;
						if(tmp > arr[i-1]) {
							min5 = tmp;
							break;
						}
					}
					int min = min(min2,min(min3,min5));
					arr[i] = min;
				}
				return arr[index-1];

						    }
};
