/// Lab 2, Dynamic Array
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// Lab2.cpp

template <class DataType>
void DynamicCheckBook<DataType>::doubleArray()
{
	capacity = 2 * numChecks;
	DataType *tempChecks = new DataType[capacity]; // dynamically allocate a tempChecks array of size two times the checksMade

	// copy the value of the checks array to the tempChecks array
	for (int i = 0; i < numChecks; i++)
		tempChecks[i] = checks[i];

	delete[] checks; // delete the elements in the array of checks
	checks = tempChecks; // make checks point to the tempChecks array address
	tempChecks = NULL; // make the tempChecks point to NULL
}

template <class DataType>
DynamicCheckBook<DataType>::DynamicCheckBook()
{
	balance = 0;
	numChecks = 0;
	lastDeposit = 0;
	capacity = 2; // assign value of 2 to capacity
	checks = new DataType[capacity]; // dynamically allocate checks array of size capacity(2)
}

template <class DataType>
DynamicCheckBook<DataType>::DynamicCheckBook(const float &initBalance)
{
	balance = initBalance;
	numChecks = 0;
	lastDeposit = 0;
	capacity = 2; // assign value of 2 to capacity
	checks = new DataType[capacity]; // dynamically allocate checks array of size capacity(2)
}

template <class DataType>
DynamicCheckBook<DataType>::~DynamicCheckBook()
{
	delete[] checks; // delete the element in the checks array
	checks = NULL; // make checks point to NULL
}

template <class DataType>
void DynamicCheckBook<DataType>::setBalance(const float &BalanceAmount)
{
	balance = BalanceAmount;
}

// returns false if amount > balance; otherwise, returns true
template <class DataType>
bool DynamicCheckBook<DataType>::writeCheck(const DataType &checkAmount)
{
	if (checkAmount > balance)
		return false;

	balance -= checkAmount;

	// if the checks array is full...
	if ( numChecks == capacity )
		doubleArray(); // double the size of the checks array

	checks[numChecks] = checkAmount; // add the new check to the checks array
	numChecks++; // add a check to the previous numChecks

	return true;
}

template <class DataType>
void DynamicCheckBook<DataType>::deposit(const float &depositAmount)
{
	balance += depositAmount;
	lastDeposit = depositAmount;
}

template <class DataType>
float DynamicCheckBook<DataType>::getBalance() const
{
	return balance;
}

template <class DataType>
DataType DynamicCheckBook<DataType>::getLastCheck() const
{
	return checks[numChecks - 1];
}

template <class DataType>
float DynamicCheckBook<DataType>::getLastDeposit() const
{
	return lastDeposit;
}

template <class DataType>
int DynamicCheckBook<DataType>::getNumChecks() const
{
	return numChecks;
}

// Client must free the dynamic array when the client is done with it to prevent memory leak
template <class DataType>
DataType* DynamicCheckBook<DataType>::getChecks() const
{
	DataType *copyOfChecks = new DataType[numChecks]; // dynamically allocate copyOfChecks array that has size the same as the checks array

	// copy the elements of the checks array to the copyOfChecks array
	for (int i = 0; i < numChecks; i++)
		copyOfChecks[i] = checks[i];

	return copyOfChecks; // returns the address of the copyOfChecks array
}
