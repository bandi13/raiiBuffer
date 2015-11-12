//
// Created by andras on 5/21/15.
//

#ifndef BUSE_CPP_RAIIBUFFERALIGNED_H
#define BUSE_CPP_RAIIBUFFERALIGNED_H

#include "raiiBuffer.h"
#include <stdint.h>

class raiiBufferAligned : public raiiBuffer {
public:
	raiiBufferAligned() : raiiBuffer() {}
	raiiBufferAligned(uint64_t size);
	raiiBufferAligned(raiiBufferAligned &&other) {
		buf = other.buf; bufSiz = other.bufSiz; avgSiz = other.avgSiz;
		other.buf = NULL; other.bufSiz = 0; other.avgSiz = 0;
	}
	virtual uint64_t setSize(uint64_t size) override;
};

#endif //BUSE_CPP_RAIIBUFFER_H
