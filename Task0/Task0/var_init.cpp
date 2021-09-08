#include <iostream>
using namespace std;

unsigned int num_var = 2;


int main()
{
	unsigned int var;
	cin >> var;
	cout << var % num_var + 1;
}