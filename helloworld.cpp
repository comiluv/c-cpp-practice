#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> message{"Hello", "C++", "World", "from", "VS Code!", "and the C++ extension!", "and Ubuntu on Windows!", "in WSL!"};
	int i = 0;

	for (const string &natmal : message)
	{
		cout << natmal << " ";
		i++;
	}
	cout << "\n";
	// cout << endl;
	return 1;
}