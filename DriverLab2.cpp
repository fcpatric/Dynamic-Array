/// Lab 2, Dynamic Array
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// DriverLab2.cpp

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::showpoint;

#include <iomanip>
using std::setprecision;

#include "Lab2.h"

int menu();

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, QUIT = 4;

int main()
{
	// programmer's identification
	cout << "Lab 2, Dynamic Array\n";
	cout << "Programmer: Fernando Ian Patricio\n";
	cout << "Programmer's ID: 1428751\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

	float balance;

	cout << "Enter the initial balance: $";
	cin >> balance;

	DynamicCheckBook<float> cb(balance);

	float amount;
	int choice;
	bool checkAccepted = false;

	cout << fixed << showpoint << setprecision(2);
	choice = menu();

	while (choice != QUIT)
	{
		if (choice == CHECK)
		{
			cout << "Enter the check amount: $";
			cin >> amount;

			if ( cb.writeCheck(amount) )
			{
				cout << "Check accepted." << endl;
				checkAccepted = true;
			}

			else
				cout << "Your balance is not high enough for that check." << endl;
		}

		else if (choice == DEPOSIT)
		{
			cout << "Enter deposit amount: $";
			cin >> amount;
			cb.deposit(amount);
			cout << "Deposit accepted." << endl;
		}

		else if (choice == BALANCE)
			cout << "Your balance is $" << cb.getBalance() << endl;

		choice = menu();
	}

	if (checkAccepted)
	{
		cout << "Your last check was: S" << cb.getLastCheck() << endl;
		cout << "Your last checks are:" << endl;

		for (int i = cb.getNumChecks() - 1; i >= 0; i--)
			cout << "$" << cb.getChecks()[i] << endl; // Client must free the dynamic array when the client is done with it to prevent memory leak.
	}

	delete [] cb.getChecks();

  cout << "Press enter to exit.";
	cin.get();
}

int menu()
{
	int choice;

	cout << endl;
	cout << "1 Write a check" << endl;
	cout << "2 Make a deposit" << endl;
	cout << "3 Get the balance" << endl;
	cout << "4 Quit" << endl << endl;
	cout << "Enter a number betweem 1 and 4: ";
	cin >> choice;
	return choice;
}
