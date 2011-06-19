/* eDIP.c */
#include "edip.h"

#include <stdarg.h>
#include <strio.h>

#define ESC 0x1B

static BYTE s_edip_buf[256];

BYTE edip_packet(BYTE *str, BYTE len, ...)
{
	va_list arg;
	BYTE i;
	sprintf(s_edip_buf, "%c%c%c", ESC, str[0], str[1]);	
	va_start(arg, len);
	for(i = 0; i < len; i++)
		s_edip_buf[3 + i] = va_arg(3, BYTE);
	va_end(arg);
	edip_small_packet(s_edip_buf, len+3);
}