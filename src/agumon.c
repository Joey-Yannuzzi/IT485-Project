
#include "simple_logger.h"
#include "agumon.h"


void agumon_update(Entity *self);

void agumon_think(Entity *self);
void augumon_collision(Entity* self, Entity *other);

Entity *agumon_new(Vector3D position)
{
    Entity *ent = NULL;
    
    ent = entity_new();
    if (!ent)
    {
        slog("UGH OHHHH, no agumon for you!");
        return NULL;
    }
    ent->selectedColor = gfc_color(0.1,1,0.1,1);
    ent->color = gfc_color(1,1,1,1);
    ent->model = gf3d_model_load("models/dino.model");
    ent->think = agumon_think;
    ent->update = agumon_update;
    ent->team = TEAM_ENEMY;
    ent->bounds = gfc_box(position.x, position.y, position.z, 2, 2, 2);
    vector3d_copy(ent->position,position);
    return ent;
}

void agumon_update(Entity *self)
{
    if (!self)
    {
        slog("self pointer not provided");
        return;
    }
    vector3d_add(self->position,self->position,self->velocity);
    self->rotation.z += 0.01;
    self->bounds.x = self->position.x;
    self->bounds.y = self->position.y;
    self->bounds.z = self->position.z;
}

void agumon_think(Entity *self)
{
    if (!self)return;
    switch(self->state)
    {
        case ES_idle:
            //look for player
            break;
        case ES_hunt:
            // set move towards player
            break;
        case ES_dead:
            // remove myself from the system
            break;
        case ES_attack:
            // run through attack animation / deal damage
            break;
    }
}

void augumon_collision(Entity* self, Entity *other)
{

}
/*eol@eof*/
