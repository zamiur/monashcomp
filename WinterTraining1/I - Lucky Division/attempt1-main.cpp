#include <iostream>
using namespace std;
 
int main()
{
	for (int n = 0; n <= 1000; ++n)
	{
		bool divby4 = (n % 4) == 0;
		bool divby7 = (n % 7) == 0;
		if (divby4)
			std::cout << "YES";
		if (divby7)
			std::cout << "YES";
		if (!divby4 && !divby7)
			std::cout << "NO";
		std::cout << "\n";
	}
	return 0;
}