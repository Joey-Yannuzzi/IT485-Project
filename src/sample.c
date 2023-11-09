/* Sample entity file for testing purposes
 * Not to be be used in game
 */
#include "simple_logger.h"
#include "sample.h"

Entity *sample_new(Vector3D pos)
{
    Entity *ent = NULL;

    ent = entity_new();

    if (!ent)
    {
        slog("No sample spawning");
        return (NULL);
    }

    ent->selectedColor = gfc_color(0.1, 1, 0.1, 1);
    ent->color = gfc_color(1, 1, 1, 1);
    ent->model = gf3d_model_load("models/test.model");
    ent->think = sample_think;
    ent->update = sample_update;
    vector3d_copy(ent->position, pos);
    return (ent);
}

void sample_update(Entity *self)
{
    if (!self)
    {
        slog("Not itself");
        return;
    }

    //slog("Updating");
}

void sample_think(Entity *self)
{
    if (!self)
    {
        slog("Not itself");
        return;
    }

    //slog("Thinking");
}
