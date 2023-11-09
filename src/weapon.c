#include "simple_logger.h"
#include "weapon.h"

void weapon_update(Weapon *self);
void weapon_think(Weapon *self);

Weapon *weapon_new(Vector3D pos, rangeType type, rangeValue range)
{
    Weapon *wep = NULL;
    wep->super = entity_new();

    if (!wep->super)
    {
        slog("No weapon to spawn");
        return(NULL);
    }

    wep->super->selectedColor = gfc_color(0.1, 1, 0.1, 1);
    wep->super->color = gfc_color(1, 1, 1, 1);
    wep->super->model = gf3d_model_load("models/test.model");
    wep->think = weapon_think;
    wep->update = weapon_update;
    wep->type = type;
    wep->range = range;
    vector3d_copy(wep->super->position, pos);
    return(wep);
}

void weapon_update(Weapon *self)
{
    slog("Update function");
}

void weapon_think(Weapon *self)
{
    slog("Think function");
}
