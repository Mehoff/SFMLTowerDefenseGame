#include "Objects.h"


Objects* Objects::_instance = 0;

std::vector<Object*> & Objects::getObjects() { return objects; }
//std::vector<Enemy*>  & Objects::getEnemies() { return enemies; }