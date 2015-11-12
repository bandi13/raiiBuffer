//
// Created by andras on 5/21/15.
//

#ifndef BUSE_CPP_RAIIBUFFER_H
#define BUSE_CPP_RAIIBUFFER_H

#include <stdint.h>
#include <stddef.h>

class raiiBuffer {
public:
	raiiBuffer();
	raiiBuffer(uint64_t size);
	raiiBuffer(raiiBuffer &&other) {
		buf = other.buf; bufSiz = other.bufSiz; avgSiz = other.avgSiz;
		other.buf = NULL; other.bufSiz = 0; other.avgSiz = 0;
	}
	~raiiBuffer();
	uint64_t getSize();
	virtual uint64_t setSize(uint64_t size);
	void *getBuf();
	void setBuf(void *buf, uint64_t len);
protected:
	void *buf;
	uint64_t bufSiz;
	uint64_t avgSiz;

	uint64_t max(uint64_t a, uint64_t b);
};

#endif //BUSE_CPP_RAIIBUFFER_H
