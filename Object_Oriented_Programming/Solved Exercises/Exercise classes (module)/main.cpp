#include <iostream>
#include <cstdlib>


/**
 * Class Module.
 * Modules have an update function that prints the module name
 * only if the current iteration is less than the internal
 * data member numIterations.
 */
class Module
{
private:
	const char *name;
	unsigned short numIterations;

public:

	// Constructor with parameters
	Module(const char *nm, unsigned short niter) :
		name(nm),
		numIterations(niter)
	{ }

	// Update method
	void update(unsigned short currentIteration)
	{
		if (currentIteration < numIterations)
		{
			std::cout << name << std::endl;
		}
	}
};


int main()
{
	// Array of three modules
	// Note that in this case I call the defined constructor explicitly... ask me why in case of doubt :-D
	Module modules[3] = {
		Module("Input", 3),
		Module("Render", 7),
		Module("Logic", 10)
	};

	// "Game loop" for 10 iterations
	for (unsigned short currentIteration = 0; currentIteration < 10; ++currentIteration)
	{
		std::cout << "-- Iteration number: " << currentIteration << std::endl;

		// At each iteration, I execute all modules' update() method
		for (int moduleIndex = 0; moduleIndex < 3; ++moduleIndex)
		{
			modules[moduleIndex].update(currentIteration);
		}

		std::cout << std::endl;
	}

	system("pause");
	return 0;
}
