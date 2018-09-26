#include <stddef.h>

#include "functions.h"
#include "shm.h"

static bool set_status(struct B *target, bool status, int t1, int t2)
{
	target->status = status;
	target->t1 = t1;
	target->t2 = t2;
	return true;
}

bool i_set_status(gpio g, bool status, int t1, int t2)
{
	struct A *shm = (struct A *)shmget();
	if (shm != NULL) {
		struct B *target = &shm->gpio[g];
		bool res = false;
		if (target->active) {
			res = set_status(target, status, t1, t2);
		}
		shmdt(shm);
		return res;
	}
	return false;
}

static bool activate(struct B *target, bool active)
{
	target->active = active;
	return true;
}

bool i_activate(gpio g, bool active)
{
	struct A *shm = (struct A *)shmget();
	if (shm != NULL) {
		struct B *target = &shm->gpio[g];
		bool res = activate(target, active);
		shmdt(shm);
		return res;
	}
	return false;
}

static bool set_direction(struct B *target, bool direction)
{
	target->direction = direction;
	return true;
}

bool i_set_direction(gpio g, bool direction)
{
	struct A *shm = (struct A *)shmget();
	if (shm != NULL) {
		struct B *target = &shm->gpio[g];
		bool res = false;
		if (target->active) {
			res = set_direction(target, direction);
		}
		shmdt(shm);
		return res;
	}
	return false;
}