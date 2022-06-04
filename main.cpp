#include"Header.h"

class UintN {
private:
	int value;
public:
	UintN() { value = 0; }
	UintN(int val) { value = val; }

	//Calculating
	void CalOper(UintN Operand) {
		cout << "\nCALCULATING PART" << endl;
		Plus(Operand);
		Minus(Operand);
		Time(Operand);
		if (Operand.value==0)
		{
			cout << "\nCAN'T PERFORM DIVIDE OPERATION." << endl;
		}
		else
		{
			Divide(Operand);
			Module(Operand);
			Remainder(Operand);
		}
		cout << "END CALCULATING." << endl;
	}
	void Plus(UintN Operand) { cout << value << " + " << Operand.value << " = " << value + Operand.value << endl; }
	void Minus(UintN Operand) { cout << value << " - " << Operand.value << " = " << value - Operand.value << endl; }
	void Time(UintN Operand) { cout << value << " x " << Operand.value << " = " << value * Operand.value << endl; }
	void Divide(UintN Operand) { cout << value << " : " << Operand.value << " = " << float(value) / float(Operand.value) << endl; }
	void Module(UintN Operand) { cout << value << " MOD " << Operand.value << " = " << value % Operand.value << endl; }
	void Remainder(UintN Operand) { cout << value << " DIV " << Operand.value << " = " << value - value % Operand.value << " REMAINDER = " << value % Operand.value << endl; }

	//Comparing
	void CompareOper(UintN Operand) {
		cout << "\nCOMPARING PART" << endl;
		if (!isEqual(Operand))
		{
			cout << value << " != " << Operand.value << endl;
			if (value>Operand.value)
			{
				cout << value << " > " << Operand.value << endl;
			}
			else
			{
				cout << value << " < " << Operand.value << endl;
			}
		}
		else
		{
			cout << value << " = " << Operand.value << endl;
		}
		cout << "END COMPARING." << endl;
	}
	bool isEqual(UintN Operand) {
		if (value==Operand.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Prime Checking
	void PrimeOper(UintN Operand) {
		cout << "\nPRIME RELATED OPERATOR" << endl;
		if (isEqual(Operand))
		{
			primePrint(value, isPrime());
		}
		else
		{
			primePrint(value, isPrime());
			primePrint(Operand.value, Operand.isPrime());
		}
		value >= Operand.value ? nextPrime() : Operand.nextPrime();
		cout << "END PRIME RELATED OPERATOR." << endl;
	}
	void primePrint(int val, bool isPrime) {
		if (isPrime)
		{
			cout << val << " Is Prime" << endl;
		}
		else
		{
			cout << val << " Is Not Prime" << endl;
		}
	}
	bool isPrime() {
		if (value<=1)
		{
			return false;
		}
		for (int i = 2; i < value; i++) {
			if (value % i == 0)
				return false;
		}
		return true;
	}
	void nextPrime()
	{
		if (value <= 1) { cout << 2 << " Is The Next Prime Number." << endl; }
		UintN prime = value;
		bool found = false;
		while (!found) {
			prime.value++;
			if (prime.isPrime()) { found = true; }
		}
		cout << prime.value << " Is The Next Prime Number." << endl;
	}

	~UintN() {}
};

int main() {
	UintN num[2];
	int temp;
	int N;
	//cout << "Enter Size constant"; cin >> N;
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter " << i + 1 << " numer:\t";
		cin >> temp;
		num[i] = temp;
	}
	num[0].CalOper(num[1]);
	num[0].CompareOper(num[1]);
	num[0].PrimeOper(num[1]);
}