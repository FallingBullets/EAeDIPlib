/* eDIP.small.c */
#include "edip.h"
#include "coms.h"

#define ACK 0x06
#define NAK 0x15
#define DC1 0x12
#define DC2 0x13

BYTE small_write(BYTE len);

static BYTE s_edip_out[256];
static BYTE s_edip_rec[256];

/* write s_out to edip_COM */
BYTE small_write(BYTE len)
{
	COM_flush(edip_COM);
	COM_write(edip_COM, s_edip_out, len);
	/*wait for ACK*/
	return ack==ACK && time < small_timeout
}

BYTE edip_small_packet(BYTE *buf, BYTE len)
{
	BYTE bcc = DC1 + len, i;
	for(i = 0, i < len, i++)
		bcc += buf[i];
	sprintf(s_edip_out, "%c%c%s%c, DC1, len, buf, bcc);
	small_write();
}

BYTE *edip_small_buffer()
{
	sprintf(s_edip_out,"%c%cS%c", DC2, 1, DC2+1+'S');
	if(!small_write())
		return NULL;
	/*read sent packet into s_edip_rec*/
	return s_rec;
}

void edip_small_info(BYTE *send, BYTE *rec)
{
}