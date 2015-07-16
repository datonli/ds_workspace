#include <iostream>

using namespace std;

int main()
{
	enum color_set {
		red,
		yellow,
		blue,
		white,
		black
	};
	color_set color = red;
	cout << color << endl;

	color_set color2 = color;
	cout << color2 << endl;

	return 0;
}
