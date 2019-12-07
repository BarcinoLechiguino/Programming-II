#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::cout << "*** TEST STD ***" << std::endl;

	std::string s;

	s = "Hola";
	s += " Que tal? ";

	std::cout << s << std::endl;

	s.clear();
	std::cout << s << std::endl;

	std::string directory = "C:/path/to/directory";
	std::string file = "model.3ds";
	std::string path = directory + "/" + file;
	std::cout << path << std::endl;

	std::vector<float> v; 
	v.push_back(50);

	for (int i = 0; i < 3; ++i)
	{
		v.push_back(i);
	}

	for (int i = 0; i < 3; ++i)
	{
		v.insert(v.begin(), i);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}