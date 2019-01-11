/// Lab 2, Dynamic Array
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// Lab2.h

#ifndef LAB2_H
#define LAB2_H

template <class DataType>
class DynamicCheckBook
{
private:
	float balance;
  int numChecks; // the number of checks stored in the array
	DataType *checks; // array to store the check
	int capacity; // capacity of the checks array
	float lastDeposit;
	void doubleArray();

public:
	DynamicCheckBook();
	DynamicCheckBook(const float&);
	~DynamicCheckBook();

	void setBalance(const float&);
	bool writeCheck(const DataType&); // returns false if amount > balance; otherwise, returns true
	void deposit(const float&);

	float getBalance() const;
	DataType getLastCheck() const;
	float getLastDeposit() const;

	int getNumChecks() const;
	DataType* getChecks() const; // Client must free the dynamic array when the client is done with it to prevent memory leak
};

#include "Lab2.cpp"

#endif // LAB2_H


