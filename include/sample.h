#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#include "entity.h"

Entity *sample_new(Vector3D position);
void sample_update(Entity *self);
void sample_think(Entity *self);

#endif
