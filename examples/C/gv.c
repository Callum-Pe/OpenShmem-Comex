/* (c) 2011 University of Houston.  All rights reserved. */


#include <stdio.h>

#include <mpp/shmem.h>

long x = 10101;

int
main()
{
  int me, npes;
  long y = -1;

  start_pes(0);
  me = _my_pe();
  npes = _num_pes();

  if (me == 0) {
    y = shmem_long_g(&x, 1);
  }

  shmem_barrier_all();

  printf("%d: y = %ld\n", me, y);

  return 0;
}
