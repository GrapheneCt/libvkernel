#include "vnz/common.h"

static void *pool_addr = 0;
static unsigned int pool_index = 0;
static unsigned int pool_size = 0;

void vnzMempoolSet(void *addr, unsigned int size)
{
	*(void **)GET_SYMBOL_ADDR(pool_addr) = addr;
	GET_SYMBOL_UINT(pool_size) = size;
	GET_SYMBOL_UINT(pool_index) = 0;
}

void *vnzMempoolMalloc(unsigned int size)
{
	unsigned int index = GET_SYMBOL_UINT(pool_index);
	if ((index + size) < GET_SYMBOL_UINT(pool_size)) {
		void *addr = (void *)(GET_SYMBOL_UINT(pool_addr) + index);
		GET_SYMBOL_UINT(pool_index) += size;
		return addr;
	}
	return 0;
}

void *vnzMempoolMemalign(unsigned int size, unsigned int alignment)
{
	unsigned int new_index = (GET_SYMBOL_UINT(pool_index) + alignment - 1) & ~(alignment - 1);
	if ((new_index + size) < GET_SYMBOL_UINT(pool_size)) {
		void *addr = (void *)(GET_SYMBOL_UINT(pool_addr) + new_index);
		GET_SYMBOL_UINT(pool_index) = new_index + size;
		return addr;
	}
	return 0;
}

unsigned int vnzMempoolFreeSpace()
{
	return GET_SYMBOL_UINT(pool_size) - GET_SYMBOL_UINT(pool_index);
}

void vnzMempoolReset()
{
	GET_SYMBOL_UINT(pool_index) = 0;
}