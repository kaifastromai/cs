#include <string>
#include <iostream>
namespace std
{
template <class nClass>
nClass GetMax(nClass a, nClass b)
{
	if (a < b)
	{
		return b;
	}
	else
	{
		return 0;
	}
}



int templates(int argc, char *argv[])
{
	cout << GetMax<int>(2, 3) << endl;
	return 0;
}
} // namespace std
