/*
 * random.c
 *
 *  Created on: 2018��7��12��
 *      Author: MSI
 */


#include "common.h"
#include "random.h"


int RANDOM(unsigned char *buf, int num)
{
	int rc = 0;
	rc =  RAND_bytes(buf,num);
	return rc;
}

