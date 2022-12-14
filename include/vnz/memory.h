#ifndef _VENEZIA_MEMORY_H
#define _VENEZIA_MEMORY_H

/*

The PRIVATE state
In this state, only a task that has changed a memory region to
this state is permitted to perform a read/write access
by the L1C/L2C. This access is achieved by accessing a
virtual address that is mapped in a physical memory by the
L1 CFL2C.

The PROTECTED state
In this state, one or more tasks that belong to the
same process and that have requested a transition to this state
are permitted to perform a read access by the L1C/L2C. A task
is not permitted to perform a write access to a memory region
in this state.

The PUBLIC state
In this state, tasks of which mapping set by the ATU
is the same, that is, tasks that belong to the same process,
share data. However, a task cannot directly access a memory region
in this state. Only tasks that belong to the same process
are permitted to access, after changing a memory in this state
to the PRIVATE state or the PROTECTED state

The UNMANAGED state
This state is a state that is not managed by the kernel.
That is, this is a portion excluding the kernel management region
out of memory regions that the memory has. Because the kernel
does not manage consistency of caches in a memory region in this state,
a task must hold consistency of the caches by taking responsibility,
when a task uses this memory region.

*/

/* Simple memory management */

typedef struct VnzMemory {
	void *paddr;
	unsigned int size;
	void *vaddrVnz;
} VnzMemory;

void vnzMemoryCreate(VnzMemory *memory, void *paddr, unsigned int size);

void *vnzMemoryOpenPublic(VnzMemory *memory);

void *vnzMemoryClosePublic(VnzMemory *memory);

void *vnzMemoryOpenPrivate(VnzMemory *memory);

void *vnzMemoryClosePrivate(VnzMemory *memory);

void *vnzMemoryOpenProtected(VnzMemory *memory);

void *vnzMemoryCloseProtected(VnzMemory *memory);


/* Ext memory management */

#define VNZ_MEMORY_MODE_PROTECTED			0x100
#define VNZ_MEMORY_MODE_PRIVATE				0x10
#define VNZ_MEMORY_MODE_PUBLIC				0x1

typedef struct VnzExtMemory {
	void *paddr;
	void *vaddrManagedHeader;
	void *vaddrPublicVnz;
	void *vaddrPrivateVnz;
	void *vaddrProtectedVnz;
	unsigned int size;
} VnzExtMemory;

int vnzExtMemoryCreate(VnzExtMemory *memory);

int vnzExtMemoryOpen(VnzExtMemory *memory, int isManagedMemory, unsigned int mode, void *addr, unsigned int size);

int vnzExtMemoryClose(VnzExtMemory *memory, void **addr);

#endif /* _VENEZIA_MEMORY_H */
