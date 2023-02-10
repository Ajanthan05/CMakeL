#include <iostream>
using namespace std;

// Add hedder
//#include <Adder/adder.h>	//float add(float a, float b);
//target_include_diredtories(${PROJECT_NAME} PUBLI Adder) // after
#include <adder.h>

int main()
{
	// prints hello world
	cout << "Hello World\n";
	cout<< add(9.5f, 7.2f) <<endl;

	return 0;
}
