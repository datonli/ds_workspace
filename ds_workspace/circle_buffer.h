#include <iostream>

using namespace std;

#define MAX_BUF 2048

template <class T>
class circle_buffer_t
{
	public:
		int cb_empty(circle_buffer_t *cb);
		int cb_full(circle_buffer_t *cb);
		int init_circle_buf(circle_buffer_t cb);
		int cb_write(circle_buffer_t *g_cb,struct pcap_pkthdr* pkt_head,const u_char *data);
		int cb_read(circle_buffer_t *g_cb,struct pcap_pkthdr* pkt_head,u_char *data);

	private:
		T buf[MAX_BUF];
		uint32_t loss;
		uint32_t error;
		volatile int32_t start;
		volatile int32_t end;
		int32_t size;

};
