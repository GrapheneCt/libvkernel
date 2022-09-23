#include "vnz/common.h"
#include "vnz/vthread.h"

VnzVThreadContext vnzVThreadCreateContext(unsigned int maxVthreads, void *pVThreadProcessingResource)
{
	int(*_vnzVThreadCreateContext)(unsigned int maxVthreads, void *pVThreadProcessingResource);
	_vnzVThreadCreateContext = GET_IMAGE_OFFSET(0x73D0);
	return _vnzVThreadCreateContext(maxVthreads, pVThreadProcessingResource);
}

int vnzVThreadExecuteSync(VnzVThreadContext context, int threadSlot, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4)
{
	int(*_vnzVThreadExecuteSync)(VnzVThreadContext context, int threadSlot, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4);
	_vnzVThreadExecuteSync = GET_IMAGE_OFFSET(0x5FD6A);
	return _vnzVThreadExecuteSync(context, threadSlot, entry, arg1, arg2, arg3, arg4);
}

int vnzVThreadDeleteContext(VnzVThreadContext context)
{
	int(*_vnzVThreadDeleteContext)(VnzVThreadContext context);
	_vnzVThreadDeleteContext = GET_IMAGE_OFFSET(0x767E);
	return _vnzVThreadDeleteContext(context);
}

int vnzVThreadResourceUnlock(void *resource)
{
	int(*_vnzVThreadResourceFree)(void *resource);
	_vnzVThreadResourceFree = GET_IMAGE_OFFSET(0x7778);
	return _vnzVThreadResourceFree(resource);
}

void *vnzVThreadResourceLock(VnzVThreadContext context)
{
	void *(*_vnzVThreadResourceReset)(VnzVThreadContext context);
	_vnzVThreadResourceReset = GET_IMAGE_OFFSET(0x7756);
	return _vnzVThreadResourceReset(context);
}

VnzVThreadEvent vnzVThreadEventCreate()
{
	VnzVThreadEvent(*_vnzVThreadEventCreate)();
	_vnzVThreadEventCreate = GET_IMAGE_OFFSET(0x6634);
	return _vnzVThreadEventCreate();
}

int vnzVThreadSignal(void *resource, int threadSlot)
{
	int(*_vnzVThreadEventSet)(void *resource, int threadSlot);
	_vnzVThreadEventSet = GET_IMAGE_OFFSET(0x78AE);
	return _vnzVThreadEventSet(resource, threadSlot);
}

int vnzVThreadExecuteWithEvent(void *resource, int threadSlot, int numSignalsToWait, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4, VnzVThreadEvent event, unsigned int eventVal)
{
	int(*_vnzVThreadExecuteWithEvent)(void *resource, int threadSlot, int numSignalsToWait, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4, VnzVThreadEvent event, unsigned int eventVal);
	_vnzVThreadExecuteWithEvent = GET_IMAGE_OFFSET(0x77BC);
	return _vnzVThreadExecuteWithEvent(resource, threadSlot, numSignalsToWait, entry, arg1, arg2, arg3, arg4, event, eventVal);
}

int vnzVThreadExecuteCore(void *resource, int threadSlot, int numSignalsToWait, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4)
{
	int(*_vnzVThreadExecuteCore)(void *resource, int threadSlot, int numSignalsToWait, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4);
	_vnzVThreadExecuteCore = GET_IMAGE_OFFSET(0x7800);
	return _vnzVThreadExecuteCore(resource, threadSlot, numSignalsToWait, entry, arg1, arg2, arg3, arg4);
}

int vnzVThreadEventWait(unsigned int val)
{
	int(*_vnzVThreadEventWait)(unsigned int val);
	_vnzVThreadEventWait = GET_IMAGE_OFFSET(0x66BE);
	return _vnzVThreadEventWait(val);
}
