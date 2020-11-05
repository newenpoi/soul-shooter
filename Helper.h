#ifndef DEF_HELPER
#define DEF_HELPER

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class Helper
{
	public:
		static std::vector<int> stringToVector(const int size, const std::string& str);
	private:
		// Emp�che l'instanciation de cette classe.
		Helper() {}
};

#endif