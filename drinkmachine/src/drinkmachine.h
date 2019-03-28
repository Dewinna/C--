/*
 ============================================================================
 Name        : drinkmachine.h
 Author      : Anthony Swink
 Version     : 1
 Copyright   : ples no take
 Description : header file for soda machine program, contains functions,
 structures, and the Purchase enum.
 ============================================================================
 */

#ifndef DRINKMACHINE_H_
#define DRINKMACHINE_H_
#define STRING_BUFFER_SIZE  128
#define INVALID_INDEX -1

typedef struct _DrinkItem{		//Structure containing info for each separate drink
	int id;
	char *name;
	double price;
	int drinkLeft;
	int drinkSold;
}DrinkItem;
typedef struct _DrinkMachine{	//Structure containing info of the drink machine, including the drinks inside of it
	int version;
	int numItems;
	int  drinkLocation;
	DrinkItem *drinkItem;
}DrinkMachine;

typedef enum _Purchase{																//Enumeration handling various possible errors
	PURCHASED, INVALID, NOT_AVAILABLE, INSUFFICIENT_FUNDS, OVERLYSUFFICIENT_FUNDS
}Purchase;

//Functions
DrinkMachine *create(void);
void destroy(DrinkMachine *drinkMachine);

DrinkItem *firstDrink(DrinkMachine *drinkMachine);
DrinkItem *nextDrink(DrinkMachine *drinkMachine);

int items(DrinkMachine *drinkMachine);
int available(DrinkMachine *drinkMachine, int id);
double cost(DrinkMachine *drinkMachine, int id);
Purchase purchase(DrinkMachine *drinkMachine, int id, double pay, double *change);
void dumpDrinkMachine(DrinkMachine *drinkMachine);

#endif /* DRINKMACHINE_H_ */
