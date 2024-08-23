#ifndef BIRD_H
#define BIRD_H

struct Bird {
  int posX;
  int posY;
  float deltaY;
};

void simmulateGravity(struct Bird *b);

#endif
