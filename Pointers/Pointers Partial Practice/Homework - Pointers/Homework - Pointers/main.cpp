#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "Ex4.h"
#include "Ex5.h"
#include <cstdlib>

int main()
{
//#define EX1
#ifdef EX1
	ex1();
#endif

//#define EX2
#ifdef EX2
	ex2();
#endif

//#define EX3
#ifdef EX3
	ex3();
#endif

//#define EX4
#ifdef EX4
	ex4();
#endif

//#define EX5
#ifdef EX5
	ex5();
#endif

	system("pause");
	return 0;
}
