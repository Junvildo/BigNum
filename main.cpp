#include"Header.h"
class UintN {
private:
	unsigned int size;
	unsigned int noDigit;
	char* digit;
public:
	UintN() {
		size = 1;
		noDigit = 1;
		digit = new char[noDigit];
	}
	UintN(unsigned int N, unsigned int No, char* input) {
		size = 4 * N;
		noDigit = No;
		digit = new char[noDigit];
		strcpy(digit,input);
	}
	void Print() {
		for (size_t i = 0; i < noDigit; i++)
		{
			cout << digit[i];
		}
	}
	//HANDLING DATA
	int Ch2Int(char val) { return int(val - '0'); }
	int Int2Ch(int val) { return char(val + '0'); }
	//CALCULATING
	int Further(bool further) { return further ?  1 : 0; }
	UintN Addition(UintN other) {
		UintN result(size, noDigit + 1, digit);
		bool isFurther = false;
		for (int i = noDigit - 1; i >= 0; i--)
		{
			if (i == noDigit - 1)
			{
				result.digit[i + 1] = Int2Ch((Ch2Int(digit[i]) + Ch2Int(other.digit[i])) % 10);
			}
			else
			{
				isFurther = false;
				if ((Ch2Int(digit[i + 1]) + Ch2Int(other.digit[i + 1])) >= 10
					|| (Ch2Int(digit[i]) + Ch2Int(other.digit[i])) + Further(isFurther)) {
					isFurther = true;
				}
				result.digit[i + 1] = Int2Ch(((Ch2Int(digit[i]) + Ch2Int(other.digit[i])) + Further(isFurther)) % 10);
			}
		}
		((Ch2Int(digit[0]) + Ch2Int(other.digit[0])) >= 10
			|| (Ch2Int(digit[0]) + Ch2Int(other.digit[0])) + Further(isFurther)>=10) ? result.digit[0] = '1' : result.digit[0] = '0';
		return result;
	}
	UintN Minus(UintN other) {
		bool isFurther;
		if (isEqual(other))
		{
			UintN result(size, 1, digit);
			result.digit[0] = '0';
			return result;
		}
		else
		{
			if (isGreater(other))
			{
				UintN result(size, noDigit, digit);
				for (int i = noDigit - 1; i >= 0; i--)
				{
					isFurther = false;
					if ((Ch2Int(digit[i]) - Ch2Int(other.digit[i])) < 0) { isFurther = true; }
					result.digit[i] = Int2Ch(abs(Ch2Int(digit[i]) - Ch2Int(other.digit[i]) - Further(isFurther)));
				}
				return result;
			}
			else
			{
				UintN result(size, noDigit + 1, digit);
				for (int i = noDigit - 1; i >= 0; i--)
				{
					isFurther = false;
					if ((Ch2Int(other.digit[i]) - Ch2Int(digit[i])) < 0) { isFurther = true; }
					result.digit[i + 1] = Int2Ch(abs((Ch2Int(other.digit[i]) - Ch2Int(digit[i])) - Further(isFurther)));
				}
				result.digit[0] = '-';
				return result;
			}
		}
	}

	//COMPARING
	int getLength() {
		int result = 0;
		while (digit[result]!=NULL)
		{
			result++;
		}
		return result;
	}
	bool isEqual(UintN other) {
		if (getLength()!=other.getLength())
		{
			return false;
		}
		else
		{
			int i = 0;
			while (i<= getLength())
			{
				if (digit[i]!=other.digit[i])
				{
					return false;
				}
				i++;
			}
			return true;
		}
	}
	bool isGreater(UintN other) {
		if (getLength()>other.getLength())
		{
			return true;
		}
		else
		{
			if (getLength() < other.getLength())
			{
				return false;
			}
		}
		int i = 0;
		while (i <= getLength())
		{
			if (digit[i] == other.digit[i])
			{
				i++;
			}
			else
			{
				if (Ch2Int(digit[i])>Ch2Int(other.digit[i]))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			i++;
		}
	}

	~UintN() {}
};
int main() {
	UintN *num[2];
	char* temp;
	int N;
	cout << "Enter Number Size Constant (N):\t";
	cin >> N;
	cin.ignore();
	temp = new char[4 * N];
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter Number " << ":\t";
		cin.getline(temp, 4 * N);
		num[i] = new UintN(4 * N, strlen(temp), temp);
	}
	for (int i = 0; i < 2; i++)
	{
		num[i]->Print();
		cout << endl;
	}
	cout << "\nAddtion: ";
	num[0]->Addition(*num[1]).Print();
	cout << "\nMinus: ";
	num[0]->Minus(*num[1]).Print();
	if (num[0]->isEqual(*num[1]))
	{
		cout << endl;
		num[0]->Print();
		cout << " = ";
		num[1]->Print();
		cout << endl;
	}
	else
	{
		cout << endl;
		num[0]->Print();
		cout << " != ";
		num[1]->Print();
		cout << endl;

		if (num[0]->isGreater(*num[1]))
		{
			num[0]->Print();
			cout << " > ";
			num[1]->Print();
		}
		else
		{
			num[0]->Print();
			cout << " < ";
			num[1]->Print();
		}
	}
}