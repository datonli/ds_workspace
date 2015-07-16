

#include "circle_buffer.h"

int cb_empty(circle_buffer_t * cb)
{
	    return cb->start == cb->end;
}

 int cb_full(circle_buffer_t * cb)
{
	    return 1 == ((cb->start + cb->size - cb->end) % cb->size);
}

int init_circle_buf(circle_buffer_t * p)
{
	    if (p) {
		            p->loss     = 0;
		            p->error    = 0;
		            p->start    = 0;
		            p->end      = 0;
		            p->size     = BUF_SIZE;
       		  		memset(p->buf, 0, sizeof(pktnode_t)*BUF_SIZE);

		        return 0;
		    } else {
	            return -1;
    }	
}

 int cb_write(circle_buffer_t * g_cb,struct pcap_pkthdr* pkt_head, const u_char * data)
{
		if (pkt_head->caplen > DATA_SIZE) {
					printf("OBVIOUS_write: packet len is %d\n", pkt_head->caplen);
				}

		    if (!cb_full(g_cb)) {
			        memcpy((uint8_t *)&(g_cb->buf[g_cb->end].pkt_head), pkt_head, sizeof(struct pcap_pkthdr));
			        memcpy(g_cb->buf[g_cb->end].data, (uint8_t *)data, pkt_head->caplen);
				g_cb->end = (g_cb->end+1)%BUF_SIZE;
			        return 0;
			    } else {
			           ++g_cb->loss;
			            return -1;
			      }
}

 int cb_read(circle_buffer_t * g_cb,struct pcap_pkthdr* pkt_head, u_char * data)
{
	    int err = -1;
	        if (!cb_empty(g_cb)) {
			 memcpy((uint8_t *)pkt_head,(uint8_t *)&(g_cb->buf[g_cb->start].pkt_head), sizeof(struct pcap_pkthdr));

			if (pkt_head->caplen > DATA_SIZE) {
			printf("OBVIOUS_read: packet len is %d\n", pkt_head->caplen);
					}
				else {
	        	memcpy(data, g_cb->buf[g_cb->start].data, pkt_head->caplen);
		            err = 0;

    			g_cb->start = (g_cb->start+1)%BUF_SIZE;
		        }
	     }

		    if (err) {
			            ++ g_cb->error;
			            g_cb->start = g_cb->end;
				        }

		        return err;
}


