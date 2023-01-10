#ifndef __SHIP_H__
#define __SHIP_H__

#include "simple_json.h"

#include "gfc_list.h"
#include "gfc_text.h"
#include "gfc_config.h"

#include "gf3d_entity.h"
#include "mission.h"

typedef struct
{
    TextLine    name;           //its name identifier
    TextLine    displayName;    //its name as displayed to the user, editable by the user
    Uint32      id;             //unique ID for the station section
    Uint32      idPool;         // for facilities on this ship
    TextLine    location;       // where is the ship
    Vector3D    position;       // more specifically
    int         housing;        //how much housing is provided by this S
    float       hull,hullMax;   //when hull <= 0 ship is destroyed
    TextLine    captain;        //who is in command of the ship (usually who is in the helm)
    Mission    *mission;        // if any mission is assigned to the section (mostly for repairs or building)
    Bool        working;        // if true, the ship is working
    int         staffPositions; // how many positions there are to work
    int         staffRequired;  //how many people are needed to run the facility at a minimum
    int         staffAssigned;  //how many people are actually hired to this ship
    float       energyOutput,energyDraw;//how much is produced, how much is needed, how much we have
    int         storageCapacity;//ship total
    int         disabled;       // if the ship cannot run.  No crew, no power, no engines
    int         speed;          // top speed for the ship
    float       efficiency;     // factor for overal ship performance
    List       *facilities;     //list of ship facilities
    Entity     *entity;         // pointer to the ship entity
}Ship;

/**
 * @brief allocate a blank ship
 */
Ship *ship_new();

/**
 * @brief aggregate stats from facilities and check if everything is working
 * @param ship the ship to check;
 */
void ship_ship_check(Ship *ship);

/**
 * @brief free a ship from memory
 */
void ship_free(Ship *ship);

/**
 * @brief load a ship instance from json
 */
Ship *ship_load(SJson *json);

/**
 * @brief save a ship instance to json
 */
SJson *ship_save(Ship *ship);

/**
 * @brief create a new ship based on def
 * @param name the ship def to make
 * @param id the id to set the ship to
 * @param defaults if true, also add the default facilities to the ship, else leave it empty
 * @return NULL on error or the ship
 */
Ship *ship_new_by_name(const char *name,int id,int defaults);

/**
 * @brief set a ship's location and position
 */
void ship_set_location(Ship *ship,const char *location,Vector3D position);

#endif
