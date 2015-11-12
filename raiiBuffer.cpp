//
// Created by andras on 5/21/15.
//

#include "raiiBuffer.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

raiiBuffer::raiiBuffer() { buf = NULL; bufSiz = 0; avgSiz = 0; }
raiiBuffer::raiiBuffer(uint64_t size) {
	if((buf = malloc(size)) == NULL) { bufSiz = 0; avgSiz = 0; }
	else bufSiz = (avgSiz = size);
}
raiiBuffer::~raiiBuffer() { free(buf); }
uint64_t raiiBuffer::getSize() { return bufSiz; }
uint64_t raiiBuffer::max(uint64_t a, uint64_t b) { return a > b ? a : b; }
// We shrink only when the average size asked for is a quarter as big as we are
uint64_t raiiBuffer::setSize(uint64_t size) {
	avgSiz = (avgSiz + size) >> 1;
	if((size > bufSiz) || (avgSiz < (bufSiz >> 2))) {
		free(buf);
		if((buf = malloc(bufSiz = max(avgSiz,size))) == NULL) { bufSiz = 0; }
	}
	return bufSiz;
}
void *raiiBuffer::getBuf() { return buf; }

void raiiBuffer::setBuf(void *buf, uint64_t len) { setSize(len); memcpy(this->buf,buf,len); }

