#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0xF1,0x28,0x95,0x15,0x27,0xE4,0x53,0x83,0x57,0xFD,0x65,0xB2,
		0x18,0x7D,0x90,0x68,0xCA,0x00,0xF8,0x43,0x02,0x3D,0x44,0xCB,
		0xD0,0x81,0x6D,0x47,0x3D,0x70,0x5C,0xCF,0x19,0xF0,0x26,0x05,
		0x41,0xFD,0x59,0x13,0xC3,0x47,0x90,0xFC,0x38,0xC4,0xA8,0xE4,
		0x63,0x65,0x6E,0x10,0x3F,0xE2,0x9A,0xAB,0x8B,0x73,0x83,0xF6,
		0x84,0x87,0xF7,0x83,
		};
	static unsigned char dh512_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}
