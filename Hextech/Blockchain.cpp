#pragma once
#include "Blockchain.h"


//Blockchain Constructor 
Blockchain::Blockchain()
{
	Block genesis = createGenesisBlock();
	chain.push_back(genesis);
}

//public chain getter 
vector<Block> Blockchain::getChain()
{
	return chain;
}

//Create genesis Block
Block Blockchain::createGenesisBlock()
{
	//Get Current Time 
	time_t current;

	// Setup Initial Transaction Data 
	TransactionData d(0, "Genesis", "Genesis", time(&current));
    // creating a string of transaction data 
	string toHash$ = to_string(d.amount) + d.senderKey + d.receiverKey + to_string(d.timestamp);

	// 2 hashes to combine 
	hash<string> tDataHash; // hashes transaction data string 
	hash<string> prevHash; // re-hashes previous hash (for combination)

	//combine hashes and get size_t for block hash
	size_t hash = tDataHash(toHash$) ^ (prevHash(to_string(0)) << 1);

	Block genesis(0, d, hash);
	return genesis;

}
//Bad!!! only for demo!!!!
//we only need pointer here to demonstrate 
// manipulation of transaction data
Block* Blockchain::getLatestBlock()
{
	return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
	int index = (int)chain.size();
	size_t lasthash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
	Block newBlock(index, d, lasthash);
	chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
	vector<Block>::iterator it;
	int chainLen = (int)chain.size();

	for (it = chain.begin(); it != chain.end(); ++it)
	{
		Block currentBlock = *it;
		if (!currentBlock.isHashValid())
		{
			//INVALID!!!!
			return false;

		}

		if (it != chain.begin())
		{
			Block previousBlock = *(it - 1);
			if (currentBlock.getPreviousHash() != previousBlock.getHash())
			{
				return false;
			}
		}
	}
	return true;
}

void Blockchain::printChain()
{
	vector<Block>::iterator it;

	for (it = chain.begin(); it != chain.end(); ++it)
	{
		Block currentBlock = *it;
		printf("\n\nBlock ================================");
		printf("\nIndex: %d", currentBlock.getIndex());
		printf("\nAmount: %f", currentBlock.data.amount);
		printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
		printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
		printf("\nTimestamp: %ld", currentBlock.data.timestamp);
		printf("\nHash: %zu", currentBlock.getHash());
		printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
		printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
	}
}