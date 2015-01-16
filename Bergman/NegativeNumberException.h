using namespace std;

class NegativeNumberException
{
	char* error;
public:
	NegativeNumberException(char* e = "Negative numbers not supported");
	void printError();
};