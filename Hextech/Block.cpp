#include "Block.h"
#include "Blockchain.h"

// Constructor with params 
Block::Block(int idx, TransactionData d, size_t prevHash)
{
	index = idx;
	data = d;
	previousHash = prevHash;
	blockHash = generateHash();
}
int Block::getIndex()
{
	return index;
}
//private functions 
size_t Block::generateHash()
{
	//Creating a string of transaction data
	string toHash$ = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);

	// 2 hashes to cimbine 
	hash<string> tDataHash;  //hashes transaction data string 
	hash<string> prevHash; //re-hashes previous hash (for combination)

	
	// combine hashes and get size_t for blokc hash
	return tDataHash(toHash$) ^ (prevHash(to_string(previousHash)) << 1);

};

//public Functions 
size_t Block::getHash()
{
	return blockHash;
}
size_t  Block::getPreviousHash()
{
	return previousHash;
}

bool Block::isHashValid()
{
	return generateHash() == getHash();
}