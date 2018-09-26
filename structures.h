#ifndef __structure_h__
#define __structure_h__

typedef enum { GPIO_1, GPIO_2, GPIO_3, GPIO_4, GPIO_5, N_GPIO } gpio;

struct B {
	bool active;
	bool status;
	bool direction;
	int timestamp;
	int t1;
	int t2;
};

struct A {
	struct B gpio[N_GPIO];
};

#endif