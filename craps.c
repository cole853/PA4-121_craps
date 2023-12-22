/*
	Programmer: Cole Clark
	Date: 10/11/2020

	Description: Craps game for PA 4 (function definitions)
*/

#include "craps.h"
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
void print_game_rules(void)
{
	printf("THE RULES FOR 'CRAPS'\n\n A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called 'craps'), the player loses (i.e. the 'house' wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 'point.' To win, you must continue rolling the dice until you 'make your point.' The player loses by rolling a 7 before making the point.\n\n");

}


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
double get_bank_balance(void)
{
	double bank_balance = 0;
	printf("Please enter your bank balance: ");
	scanf("%lf", &bank_balance);

	return bank_balance;

}


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
double get_wager_amount(void)
{
	double wager = 0;
	printf("Please enter your wager amount: ");
		scanf("%lf", &wager);

		return wager;
}


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
int check_wager_amount(double wager, double balance)
{
	if (wager <= balance && wager >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


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
int roll_die(void)
{
	int dice = rand() % 6 + 1;
	return dice;

}


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
int calculate_sum_dice(int die1_value, int die2_value)
{

	int sum = die1_value + die2_value;
	return sum;

}


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
int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


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
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return 1;
	}
	else if (sum_dice == 7)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


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
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		bank_balance += wager_amount;
	}
	else if (add_or_subtract == 0)
	{
		bank_balance -= wager_amount;
	}
	return bank_balance;

}


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
void chatter_messages( int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (win_loss_neither == 1)
	{
		printf("Starting bank balance: %.2lf\n", initial_bank_balance);
		printf("Current bank balance: %.2lf\n", current_bank_balance);
		printf("YOU WON!\n\n");
	}
	else if (win_loss_neither == 0)
	{
		printf("Starting bank balance: %.2lf\n", initial_bank_balance);
		printf("Current bank balance: %.2lf\n", current_bank_balance);
		printf("you lost :,(\n\n");
	}
	else if (win_loss_neither == -1)
	{
		int chatter_line = rand() % 5 + 1;

		if (chatter_line == 1)
		{
			printf("C'mon, take a chance!\n\n");
		}
		else if (chatter_line == 2)
		{
			printf("Now is the time to bet high!!!\n\n");
		}
		else if (chatter_line == 3)
		{
			printf("Up the ante!\n\n");
		}
		else if (chatter_line == 4)
		{
			printf("Oh, you're going for broke, huh!\n\n");
		}
		else if (chatter_line == 5)
		{
			printf("Hedge your bets!!!\n\n");
		}
	}
	
	
}


/*************************************************************
* Function: show_dice()							            *
* Date Created: 10/11/2020                                  *
* Date Last Modified: 10/11/2020                            *
*															*
* Description: Prints dice roll for the player to see. With	*
*				the sum and number of rolls.				*
*															*
* Input parameters: number of rolls, dice roll 1, dice 2,	*
*					sum										*
* Returns: dice rolls, sum, and roll number					*
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
void show_dice(int rolls, int die1, int die2, int sum, int win_loss_neither, int point)
{
	if (win_loss_neither == -1)
	{
		printf("Your point is: %d\n", point);
	}
	printf("\nNumber of rolls: %d\n", rolls);
	printf("Here is your roll: %d , %d\n", die1, die2);
	printf("Sum: %d\n", sum);

}


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
void bad_wager_response(void)
{
	printf("your bet is not valid, please enter a number between 0 and your bank balance.\n");
}