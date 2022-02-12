#pragma once
#include<ctime>
#include<string>

using namespace std;

struct TransactionData {
	double amount;
	string senderKey;
	string receiverKey;
	time_t timestamp;

	TransactionData() {};

	TransactionData(double amt, string sender, string receiver, time_t time)
	{
		amount = amt;
		senderKey = sender;
		receiverKey = receiver;
		timestamp = time;
	};
};