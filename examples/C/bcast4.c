/*
 * testing behavior when PE not in active set calls broadcast
 *
 */

#include <stdio.h>

#include <mpp/shmem.h>

long pSync[_SHMEM_BCAST_SYNC_SIZE];

int
main(void)
{
  int i;
  long *target;
  static long source[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int nlong = 8;
  int me;

  start_pes(0);
  me = _my_pe();

  target = (long *) shmalloc( 8 * sizeof(*target) );

  for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1) {
    pSync[i] = _SHMEM_SYNC_VALUE;
  }
  shmem_barrier_all();

  if ( (me % 2) == 0) {
    shmem_broadcast64(target, source, nlong, 0, 0, 1, 4, pSync);
  }

  for (i = 0; i < 8; i++) {
    printf("%d: target[%d] = %ld\n", me, i, target[i]);
  }
  
  shmem_barrier_all();

  shfree(target);

  return 0;
}