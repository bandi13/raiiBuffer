//
// Created by andras on 5/21/15.
// This aligns the memory onto a page boundary

#include "raiiBufferAligned.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

raiiBufferAligned::raiiBufferAligned(uint64_t size) {
	if(posix_memalign(&buf,512,size)) { free(buf); buf = NULL; bufSiz = 0; avgSiz = 0; }
	else bufSiz = (avgSiz = size);
}
// We shrink only when the average size asked for is a quarter as big as we are
uint64_t raiiBufferAligned::setSize(uint64_t size) {
	avgSiz = (avgSiz + size) >> 1;
	if((size > bufSiz) || (avgSiz < (bufSiz >> 2))) {
		free(buf);
		if(posix_memalign(&buf,512,bufSiz = max(avgSiz,size))) { free(buf); buf = NULL; bufSiz = 0; }
	}
	return bufSiz;
}

