#ifndef L_FILE
#define L_FILE
#include <stdio.h>
#include <stdlib.h>
/**
 * struct cars - linked list of cars.
 * @id: id
 * @lap: lap done
 * @next: points to the next car
 */
typedef struct cars
{
	int id;
	int lap;
	struct cars *next;
} cars_t;


void race_state(int *id, size_t size);
int check_car(cars_t *car, int id);
cars_t *add_car(cars_t *head, int id);
void get_stat(cars_t *car);
void get_lap(cars_t *car, int id);

#endif
