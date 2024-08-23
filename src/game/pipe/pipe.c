#include "pipe.h"
#include <stdlib.h>

struct Pipe *generatePipe() {
  struct Pipe *pipe = malloc(sizeof(struct Pipe));
  return pipe;
}
