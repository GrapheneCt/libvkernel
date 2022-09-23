#include "vnz/common.h"
#include "vnz/memory.h"

void vnzMemoryCreate(VnzMemory *memory, void *paddr, unsigned int size)
{
	void(*_vnzMemoryCreate)(VnzMemory *memory, void *paddr, unsigned int size);
	_vnzMemoryCreate = GET_IMAGE_OFFSET(0x5FC14);
	_vnzMemoryCreate(memory, paddr, size);
}

void *vnzMemoryOpenPublic(VnzMemory *memory)
{
	void*(*_vnzMemoryOpenPublic)(VnzMemory *memory);
	_vnzMemoryOpenPublic = GET_IMAGE_OFFSET(0x5FC22);
	return _vnzMemoryOpenPublic(memory);
}

void *vnzMemoryClosePublic(VnzMemory *memory)
{
	void*(*_vnzMemoryClosePublic)(VnzMemory *memory);
	_vnzMemoryClosePublic = GET_IMAGE_OFFSET(0x5FC52);
	return _vnzMemoryClosePublic(memory);
}

void *vnzMemoryOpenPrivate(VnzMemory *memory)
{
	void*(*_vnzMemoryOpenPrivate)(VnzMemory *memory);
	_vnzMemoryOpenPrivate = GET_IMAGE_OFFSET(0x5FC82);
	return _vnzMemoryOpenPrivate(memory);
}

void *vnzMemoryClosePrivate(VnzMemory *memory)
{
	void*(*_vnzMemoryClosePrivate)(VnzMemory *memory);
	_vnzMemoryClosePrivate = GET_IMAGE_OFFSET(0x5FCBC);
	return _vnzMemoryClosePrivate(memory);
}

void *vnzMemoryOpenProtected(VnzMemory *memory)
{
	void*(*_vnzMemoryOpenProtected)(VnzMemory *memory);
	_vnzMemoryOpenProtected = GET_IMAGE_OFFSET(0x5FCF6);
	return _vnzMemoryOpenProtected(memory);
}

void *vnzMemoryCloseProtected(VnzMemory *memory)
{
	void*(*_vnzMemoryCloseProtected)(VnzMemory *memory);
	_vnzMemoryCloseProtected = GET_IMAGE_OFFSET(0x5FD30);
	return _vnzMemoryCloseProtected(memory);
}

int vnzExtMemoryCreate(VnzExtMemory *memory)
{
	int(*_vnzExtMemoryCreate)(VnzExtMemory *memory);
	_vnzExtMemoryCreate = GET_IMAGE_OFFSET(0x11ED0);
	return _vnzExtMemoryCreate(memory);
}

int vnzExtMemoryOpen(VnzExtMemory *memory, int isManagedMemory, unsigned int mode, void *addr, unsigned int size)
{
	int(*_vnzExtMemoryOpen)(VnzExtMemory *memory, int isManagedMemory, unsigned int mode, void *addr, unsigned int size);
	_vnzExtMemoryOpen = GET_IMAGE_OFFSET(0x11EEC);
	return _vnzExtMemoryOpen(memory, isManagedMemory, mode, addr, size);
}

int vnzExtMemoryClose(VnzExtMemory *memory, void **addr)
{
	int(*_vnzExtMemoryClose)(VnzExtMemory *memory, void **addr);
	_vnzExtMemoryClose = GET_IMAGE_OFFSET(0x11FAE);
	return _vnzExtMemoryClose(memory, addr);
}
