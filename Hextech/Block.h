#pragma once
#include <ctime>
#include "TransactionData.h"

class Block
{
private:
	int index;
	size_t blockHash;
	size_t previousHash;
	size_t generateHash();

public:
	//Constructor
	Block(int idx, TransactionData d, size_t prevHash);

	//Get Index 
	int getIndex();

	//Get Original Hash
	size_t getHash();

	//Get previous Hash
	size_t getPreviousHash();

	//Transaction Data
	TransactionData data;

	//validate Hash
	bool isHashValid();

};