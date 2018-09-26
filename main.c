#include <stdbool.h>
#include <stdio.h>

#include "functions.h"
#include "structures.h"

struct A gpios;

int main() {
	printf("Activate GPIO1 result = %d\n", i_activate(GPIO_1, true));
	printf("Set GPIO1 direction result = %d\n", i_set_direction(GPIO_1, IN));
	printf("Set GPIO2 direction result = %d\n", i_set_direction(GPIO_2, OUT));
 }