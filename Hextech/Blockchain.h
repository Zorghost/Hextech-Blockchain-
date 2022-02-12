#pragma once
#include <vector>
#include "Block.h"

class Blockchain
{
private:
	Block createGenesisBlock();
	vector<Block> chain;

public:
	// Constructor
	Blockchain();

	//public Functions
	vector<Block> getChain();
	Block* getLatestBlock();
	void addBlock(TransactionData data);
	bool isChainValid();
	void printChain();

	

};