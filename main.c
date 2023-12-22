/*
	Programmer: Cole Clark 
	Date: 10/11/2020
	
	Description: Craps game for PA 4
*/

#include "craps.h"

int main(void)
{
	double starting_bank_balance = 0;
	int good_bad_wager = 0, rolls = 2;

	srand((unsigned int)time(NULL));

	print_game_rules();

	system("pause");
	system("cls"); // clears screen

	starting_bank_balance = get_bank_balance(); //get a starting bank balance from the user

	double wager = get_wager_amount(); //get a wager amount from the user
	good_bad_wager = check_wager_amount(wager, starting_bank_balance); //check to see if the wager is less than or equal to bank balance and greater than or equal to 0. returns 1 if wager is good. returns 0 if bad.

	while (good_bad_wager != 1) //checks to see if the wager is good. if it isnt then the following repeats.
	{
		bad_wager_response(); // prints a message to the user 
		wager = get_wager_amount(); // collects another wager amount
		good_bad_wager = check_wager_amount(wager, starting_bank_balance); // checks the new wager to see if it is in the acceptable range
	}

	int die1 = roll_die(); //rolls 1 die
	int die2 = roll_die(); // rolls another die
	int sum = calculate_sum_dice(die1, die2); // sums the two dice
	int point = sum; //sets point equal to sum
	
	show_dice(1, die1, die2, sum, 0, 0); // prints dice amount, sum, and roll number

	int add_or_subtract = is_win_loss_or_point(sum); // determines whether the player won (returns 1), lost (returns 0), or neither (returns -1) on the first roll.
	
	if (add_or_subtract == -1) // if the player didnt win or lose print a chatter message
	{
		chatter_messages( add_or_subtract, starting_bank_balance, starting_bank_balance);
	}
	while (add_or_subtract == -1) // while the player hasn't won or lost repeat the following
	{
			wager = get_wager_amount(); // collect a new wager from the player
			good_bad_wager = check_wager_amount(wager, starting_bank_balance); // check to see if the wager is in the acceptable range

			while (good_bad_wager != 1) // checks to see if the wager is good. if it isnt then the following repeats
			{
				bad_wager_response(); // prints a message to the user
				wager = get_wager_amount(); // collects a new wager
				good_bad_wager = check_wager_amount(wager, starting_bank_balance); // checks the new wager to see if it is in the acceptable range
			}

			system("cls"); // clears the screen after a roll


			int die1 = roll_die(); // rolls one die
			int die2 = roll_die(); // rolls another die
			int sum = calculate_sum_dice(die1, die2); // sums the two dice

			show_dice(rolls, die1, die2, sum, add_or_subtract, point); // prints the dice, sum, and roll number

			add_or_subtract = is_point_loss_or_neither(sum, point); // determines whether the player won (returns 1), lost (returns 0), or neither (returns -1) after the first roll
			
			if (add_or_subtract == -1) // if the player didnt win or lose print a chatter message
			{
				chatter_messages(add_or_subtract, starting_bank_balance, starting_bank_balance);
			}

			++rolls; // add one to the number of rolls

	}
	if (add_or_subtract == 1 || add_or_subtract == 0) // if the player won or lost
	{
		double new_bank_balance = adjust_bank_balance(starting_bank_balance, wager, add_or_subtract); // update the bank balance

		chatter_messages( add_or_subtract, starting_bank_balance, new_bank_balance); // print a chatter message
	}

	return 0;
}
