#include <unistd.h>
#include <netdb.h>
#include <iostream>

using namespace std;

int main()
{
	char hostname[1024];
	hostname[1023] = '\0';
	gethostname(hostname,1023);
	cout << hostname << endl;
	struct hostent *h ;
	h = gethostbyname(hostname);
	cout << h->h_name << endl;
	return 0;
}
