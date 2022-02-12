#include "Blockchain.h"

using namespace std;


int main()
{
    // Start Blockchain
    Blockchain Hextech;

    // Data for first block
    time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
    Hextech.addBlock(data1);

    time_t data2Time;
    TransactionData data2(0.2233, "Martha", "Fred", time(&data2Time));
    Hextech.addBlock(data2);

    // Let's see what's in the awesomeCoin blockchain!
    Hextech.printChain();

    // Is it valid?
    printf("\nIs chain still valid? %d\n", Hextech.isChainValid());

    // Someone's getting sneaky
    Block* hackBlock = Hextech.getLatestBlock();
    hackBlock->data.amount = 10000; // Oh yeah!
    hackBlock->data.receiverKey = "Jon"; // mwahahahaha!

    // Let's look at data
    Hextech.printChain();

    // Awww! Why is it not valid?
    printf("\nIs chain still valid? %d\n", Hextech.isChainValid());

    return 0;

}



