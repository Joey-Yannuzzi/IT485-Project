#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "entity.h"

typedef enum
{
    RT_MELEE,
    RT_RANGED,
    RT_AMMO
}rangeType;

typedef enum
{
    RV_SHORT,
    RV_MEDIUM,
    RV_LONG
}rangeValue;

typedef struct Weapon
{
    struct Entity_S *super;
    Uint8 held; //for checking if weapon is being held
    Entity *owner; //owner of the weapon, NULL if not held
    int ammo; //ammunition for the weapon, -1 if not apllicable

    rangeType type; //type of range
    rangeValue range; //range value

    void (*think)(struct Weapon *self);
    void (*update)(struct Weapon *self);
}Weapon;

Weapon *weapon_new(Vector3D pos, rangeType type, rangeValue range);

#endif
