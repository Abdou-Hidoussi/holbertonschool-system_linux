#include "laps.h"
/**
 * check_car - check if car exist in list.
 * @car: list of cars
 * @id: id to look for
 * Return: 0 or 1
 */
int check_car(cars_t *car, int id)
{
	while (car)
	{
		if (car->id == id)
			return (0);

		car = car->next;
	}
	return (1);
}
/**
 * add_car - add car to a list.
 * @head: list of cars
 * @id: id to add
 * Return: head of list
 */
cars_t *add_car(cars_t *head, int id)
{
	static cars_t *befor, *new, *car;

	car = head;
	new = malloc(sizeof(cars_t));
	new->id = id;
	new->lap = 0;
	new->next = NULL;
	if (!car)
	{
		printf("Car %i joined the race\n", new->id);
		return (new);
	}
	befor = NULL;
	while (car)
	{
		if (car->id > id)
		{
			if (befor)
				befor->next = new;
			else
				befor = new;
			new->next = car;
			printf("Car %i joined the race\n", new->id);
			return (befor);
		}
		befor = car;
		car = car->next;
	}
	printf("Car %i joined the race\n", new->id);
	befor->next = new;
	return (head);
}
/**
 * get_stat - show laps done by cars
 * @car: list of cars
 */
void get_stat(cars_t *car)
{
	printf("Race state:\n");
	while (car)
	{
		printf("Car %i [%i laps]\n", car->id, car->lap);
		car = car->next;
	}
}
/**
 * get_lap - add lap to a car.
 * @car: list of cars
 * @id: id of car to make a lap
 */
void get_lap(cars_t *car, int id)
{
	while (car)
	{
		if (car->id == id)
			car->lap += 1;

		car = car->next;
	}
}
/**
 * race_state - Task 0
 * @id: list of ids
 * @size: size if *id
 */
void race_state(int *id, size_t size)
{
	static cars_t *car;
	cars_t *new;
	size_t i;

	if (size == 0 || id == NULL)
	{
		while (car)
		{
			new = car;
			car = car->next;
			free(new);
		}
		free(car);
		return;
	}

	for (i = 0; i < size; i++)
		get_lap(car, id[i]);

	for (i = 0; i < size; i++)
	{
		if (check_car(car, id[i]))
			car = add_car(car, id[i]);
	}
	get_stat(car);
}
