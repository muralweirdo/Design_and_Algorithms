#include <iostream>
using namespace std;

class Multiply {
	private:
		int multiplier;
		int multiplicand;
		int multiplierSize;
		int multiplicandSize;
		int *arrayMultiplier;
		int *arrayMultiplicand;
	public:
		Multiply();
		~Multiply();
		void get();
		long mul();
		void checkingSize(int num);
		void assigningValuesToMultiplicand();
		void assigningValuesToMultiplier();
		void assigningValuesToMultiplierSingle();
		void assigningValuesToMultiplicandSingle();
};

Multiply::Multiply() {
	multiplier = 0;
	multiplicand = 0;
	multiplierSize = 0;
	multiplicandSize = 0;
	arrayMultiplier = NULL;
	arrayMultiplicand = NULL;
}

Multiply::~Multiply() {
	delete arrayMultiplicand;
	delete arrayMultiplier;
}

void Multiply::get() {
	cout<<"Enter Multiplier = ";
	cin>>multiplier;
	cout<<"Enter Multiplicand = ";
	cin>>multiplicand;
}

long Multiply::mul() {

	checkingSize(multiplier);
	checkingSize(multiplicand);
	if(multiplicandSize > 2 && multiplierSize > 2) {
		if (multiplierSize % 2 != 0) {
			multiplierSize += 1;
		}
		multiplierSize = multiplierSize / 2;
		arrayMultiplier = new int[multiplierSize];
		assigningValuesToMultiplier();

		if (multiplicandSize % 2 != 0) {
			multiplicandSize += 1;
		}
		multiplicandSize = multiplicandSize / 2;
		arrayMultiplicand = new int [multiplicandSize];
		assigningValuesToMultiplicand();

		int num = 1;
		long result = 0;
		int temp = 0;
		for (int i = 0; i < multiplicandSize; i++) {
			int innernum = 1;
			innernum *= num;
			for (int j = 0; j < multiplierSize; j++) {
				temp = arrayMultiplicand[i] * arrayMultiplier[j];
				temp *= innernum;
				result += temp;
				temp = 0;
				innernum *= 100;
			}
			num *= 100;
		}
		return result;
	}
	arrayMultiplier = new int[multiplierSize];
	arrayMultiplicand = new int[multiplicandSize];
	assigningValuesToMultiplierSingle();
	assigningValuesToMultiplicandSingle();
	long result = 0;
	int temp = 0;
	int num = 1;
	for (int i = 0; i < multiplicandSize; i++) {
		int innernum = 1;
		innernum *= num;
		for (int j = 0; j < multiplierSize; j++) {
			temp = arrayMultiplicand[i] * arrayMultiplier[j];
			temp *= innernum;
			result += temp;
			temp = 0;
			innernum *= 10;
		}
		num *= 10;
	}
	return result;
}


void Multiply::checkingSize(int num) {
	int temp = num;
	int count = 0;
	while(temp % 10 != 0) {
		temp = temp / 10;
		count += 1;
	}

	if (num == multiplier) {
		multiplierSize = count;
		multiplicandSize = count;
	}
	else
		multiplicandSize = count;
}

void Multiply::assigningValuesToMultiplier() {
	int temp = multiplier;
	int count = 0;
	int num = 0;
	while(temp % 10 != 0) {
		num  = temp % 10;
		temp = temp / 10;
		arrayMultiplier[count] = num;
		num  = temp % 10;
		num  *= 10;
		arrayMultiplier[count]  += num;
		temp = temp / 10;
		count += 1;
	}
}



void Multiply::assigningValuesToMultiplicand() {
	int temp = multiplicand;
	int count = 0;
	int num = 0;
	while(temp % 10 != 0) {
		num  = temp % 10;
		temp = temp / 10;
		arrayMultiplicand[count] = num;
		num  = temp % 10;
		num  *= 10;
		arrayMultiplicand[count]  += num;
		temp = temp / 10;
		count += 1;
	}
}

void Multiply::assigningValuesToMultiplierSingle() {
	int temp = multiplier;
	int count = 0;
	int num = 0;
	while(temp % 10 != 0) {
		num  = temp % 10;
		temp = temp / 10;
		arrayMultiplier[count] = num;
		count += 1;
	}
}

void Multiply::assigningValuesToMultiplicandSingle() {
	int temp = multiplicand;
	int count = 0;
	int num = 0;
	while(temp % 10 != 0) {
		num  = temp % 10;
		temp = temp / 10;
		arrayMultiplicand[count] = num;
		count += 1;
	}
}

int main() {
	Multiply obj;
	obj.get();
	long temp = obj.mul();
	cout<<temp<<endl;
	return 0;
}
