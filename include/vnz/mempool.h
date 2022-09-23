#ifndef _VENEZIA_MEMPOOL_H
#define _VENEZIA_MEMPOOL_H

void vnzMempoolSet(void *addr, unsigned int size);

void *vnzMempoolMalloc(unsigned int size);

void *vnzMempoolMemalign(unsigned int size, unsigned int alignment);

unsigned int vnzMempoolFreeSpace();

void vnzMempoolReset();

#endif /* _VENEZIA_MEMPOOL_H */