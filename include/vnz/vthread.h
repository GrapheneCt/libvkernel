#ifndef _VENEZIA_VTHREAD_H
#define _VENEZIA_VTHREAD_H

#include "common.h"

typedef void* VnzVThreadEvent;
typedef int VnzVThreadContext;
typedef int(*VnzVThreadEntry)(int a1, int a2, int a3, int a4);

/**
 * Create V-Thread execution context
 *
 * @param[in] maxVthreads - maximum number of V-Threads planned to run in this context
 * @param[in] pVThreadProcessingResource - V-Thread processing resource pointer, passed from ARM side
 *
 * @return VnzVThreadContext, 0 on error.
 */
VnzVThreadContext vnzVThreadCreateContext(unsigned int maxVthreads, void *pVThreadProcessingResource);

/**
 * Delete V-Thread execution context
 *
 * @param[in] context - V-Thread execution context to delete
 *
 * @return 0, <0 on error.
 */
int vnzVThreadDeleteContext(VnzVThreadContext context);

/**
 * Execute V-Thread
 *
 * @param[in] resource - processing resource locked with vnzVThreadResourceLock()
 * @param[in] threadSlot - thread execution slot
 * @param[in] numSignalsToWait - amount of signals to wait on thread execution slot before starting this thread
 * @param[in] entry - V-Thread entry
 * @param[in] arg1 - user argument 1
 * @param[in] arg2 - user argument 2
 * @param[in] arg3 - user argument 3
 * @param[in] arg4 - user argument 4
 *
 * @return 0, <0 on error.
 */
int vnzVThreadExecuteCore(void *resource, int threadSlot, int numSignalsToWait, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4);

/**
 * Execute V-Thread and wait for completion
 *
 * @param[in] context - V-Thread execution context
 * @param[in] threadSlot - thread execution slot
 * @param[in] entry - V-Thread entry
 * @param[in] arg1 - user argument 1
 * @param[in] arg2 - user argument 2
 * @param[in] arg3 - user argument 3
 * @param[in] arg4 - user argument 4
 *
 * @return 0, <0 on error.
 */
int vnzVThreadExecuteSync(VnzVThreadContext context, int threadSlot, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4);

/**
 * Execute V-Thread and signal event to parent thread on completion
 *
 * @param[in] resource - processing resource locked with vnzVThreadResourceLock()
 * @param[in] threadSlot - thread execution slot
 * @param[in] numSignalsToWait - amount of signals to wait on thread execution slot before starting this thread
 * @param[in] entry - V-Thread entry
 * @param[in] arg1 - user argument 1
 * @param[in] arg2 - user argument 2
 * @param[in] arg3 - user argument 3
 * @param[in] arg4 - user argument 4
 * @param[in] event - event to set when this thread completes
 * @param[in] eventVal - event value to set when this thread completes
 *
 * @return 0, <0 on error.
 */
int vnzVThreadExecuteWithEvent(void *resource, int threadSlot, int numSignalsToWait, VnzVThreadEntry entry, int arg1, int arg2, int arg3, int arg4, VnzVThreadEvent event, unsigned int eventVal);

/**
 * Send sync signal to other V-Thread slot within execution context
 *
 * @param[in] resource - processing resource locked with vnzVThreadResourceLock()
 * @param[in] threadSlot - thread execution slot to send sync signal to
 *
 * @return 0, <0 on error.
 */
int vnzVThreadSignal(void *resource, int threadSlot);

/**
 * Lock V-Thread processing resource
 *
 * @param[in] context - V-Thread execution context
 *
 * @return V-Thread resource pointer, NULL on error.
 */
void *vnzVThreadResourceLock(VnzVThreadContext context);

/**
 * Unlock V-Thread processing resource
 *
 * @param[in] resource - processing resource locked with vnzVThreadResourceLock()
 *
 * @return 0, <0 on error.
 */
int vnzVThreadResourceUnlock(void *resource);

/**
 * Create V-Thread sync event
 *
 *
 * @return VnzVThreadEvent, NULL on error.
 */
VnzVThreadEvent vnzVThreadEventCreate();

/**
 * Wait for V-Thread sync event
 *
 * @param[in] val - event value to wait for
 *
 * @return 0, <0 on error.
 */
int vnzVThreadEventWait(unsigned int val);

#endif /* _VENEZIA_VTHREAD_H */
