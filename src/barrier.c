#include "state.h"
#include "comms.h"
#include "warn.h"
/* #include "dispatch.h" */
#include "comms.h"
#include "hooks.h"

/* @api */
void
shmem_barrier_all(void)
{
  __comms_barrier_all();
}

/* @api */
void
shmem_barrier(int PE_start, int logPE_stride, int PE_size, long *pSync)
{
  __comms_barrier(PE_start, logPE_stride, PE_size, pSync);
}

#ifdef HAVE_PSHMEM_SUPPORT
#pragma weak pshmem_barrier_all = shmem_barrier_all
#pragma weak pshmem_barrier_all = shmem_barrier_all
#pragma weak pshmem_barrier = shmem_barrier
#endif /* HAVE_PSHMEM_SUPPORT */
