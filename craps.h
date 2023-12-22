/*
	Programmer: Cole Clark
	Date: 10/11/2020

	Description: Craps game for PA 4 (Header and function prototypes)
*/

#ifndef CRAPS_H
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*************************************************************
* Function: print_game_rules()				                *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Prints the rules of the game "craps"			*
*															*
* Input parameters: void                                    *
* Returns: game rules                                       *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void print_game_rules(void);


/*************************************************************
* Function:	get_bank_balance()				                *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Prompts the player for an initial bank		*
*				balance from which wagering will be added	*
*				or subtracted								*
*															*
* Input parameters: void                                    *
* Returns: bank balance                                     *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
double get_bank_balance(void);


/*************************************************************
* Function: get_wager_amount()					            *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: prompts the player for a wager on a			*
*				particular roll.							*
*															*
* Input parameters: void                                    *
* Returns: wager amount                                     *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
double get_wager_amount(void);


/*************************************************************
* Function: check_wager_amount()					        *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Checks to see if the wager is within the		*
*				limits of the player's available balance.	*
*															*
* Input parameters: wager, current balance                  *
* Returns: 0 if the wager exceeds the balance, 1 otherwise  *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int check_wager_amount(double wager, double balance);


/*************************************************************
* Function: roll_die()					                    *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Rolls 1 die by randomly generating a number	*
*				between 1 and 6.							*
*															*
* Input parameters: void                                    *
* Returns: random number between 1 and 6                    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int roll_die(void);


/*************************************************************
* Function:	calculate_sum_dice				                *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020							*
*															*
* Description: Sums together the values of the two dice		*
*				and returns the result.						*
*															*
* Input parameters: value of two dice                       *
* Returns: Sum of two dice                                  *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value);


/*************************************************************
* Function: is_win_loss_or_point()							*
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Determines the result of rhte first dice		*
*				roll if sum is 7 or 11 the player wins,		*
*				if 2, 3, 12 the player loses,				*
*				if sum is 4, 5, 6, 8, 9, 10 the sum			*
*				becomes point.								*
*															*
* Input parameters: sum of the first dice roll              *
* Returns: 1 if win, 0 if loss, -1 if point                 *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int is_win_loss_or_point(int sum_dice);


/*************************************************************
* Function: is_point_loss_or_neither()					    *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Determines the result of any successive		*
*				roll after the first roll.					*
*															*
* Input parameters: sum of dice roll, point value           *
* Returns: 1 if equals point, 0 if equals 7, otherwise -1   *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value);


/*************************************************************
* Function: adjust_bank_balance()					        *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: if add_or_subract is 1, then the wager		*
*				amount is added to the bank_balance.		*
*				if add_or_subtract is 0, then the wager		*
*				amount is subtracted from the bank_balance.	* 
*				Otherwise the bank_balance remains the same.*
*															*
* Input parameters: bank_balance, wager_amount,				* 
*					add_or_subtract                         *
* Returns: bank_balance                                     *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);


/*************************************************************
* Function: chatter_message()					            *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: prints an appropriate message depending on	*
*				the number of rolls taken so far by the		*
*				player, the current balance, and whether	*
*				or not the player just won the roll.		*
*															*
* Input parameters: number of rolls, win_loss_neither,		*
*					initial_bank_balance,					*
*					current_bank_balance                    *
* Returns: returns a message based on the previous roll     *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void chatter_messages( int win_loss_neither, double initial_bank_balance, double current_bank_balance);


/*************************************************************
* Function: show_dice()							            *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Prints dice roll for the player to see.		*
*															*
* Input parameters: dice roll 1 and 2		                *
* Returns: dice rolls									    *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void show_dice(int rolls, int die1, int die2, int sum, int win_loss_neither, int point);


/*************************************************************
* Function: bad_wager_response()							*
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: prints a response to the player if wager is	*
*				invalid.									*
*															*
* Input parameters: void					                *
* Returns: invalid wager message							*
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void bad_wager_response(void);

#endif