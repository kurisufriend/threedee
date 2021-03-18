#include "globals.h"

bool global::running = true;
vector2 global::mousePos;
entityList2D global::entList;
entityList3D global::entList3D;
camera global::cam(vector3(0, 0, 0), vector3(0, 0, 0));