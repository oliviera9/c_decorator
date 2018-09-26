#include <stdbool.h>

#include "structures.h"

#define IN false
#define OUT true

bool i_set_status(gpio g, bool status, int t1, int t2);
bool i_set_direction(gpio g, bool direction);
bool i_activate(gpio g, bool active);
