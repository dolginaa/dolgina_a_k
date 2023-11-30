
#include <iostream>
#include <vector>
#include <iosfwd>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <initializer_list>

class Mat
{
private:
	int size1(0);
	int size2(0);
	std::vector<double>arr[];
	//int arrayset[0][0];

public:
	Mat(const int size11, const int size22)
	{
		if (size11 <= 0 || size22 <= 0)
		{
			throw std::invalid_argument("wrong size");
		}
		size1 = size11;
		size2 = size22;
		arrayset.resize(size1, size2);
		for (int i = 0;i < size1;++i)
		{
			for (int j = 0;j < size2;++j)
			{
				arrayset[i][j] = 0;
			}
		}
		return *this;
	}

	Mat(const Mat& copy)
	{
		if ((size1 != copy.size1) || (size2 != copy.size2))
		{
			throw std::invalid_argument("different sizes");
		}
		size1 = copy.size1;
		size2 = copy.size2;
		arrayset.resize(size1, size2);
		for (int i = 0;i < size1;++i)
		{
			for (int j = 0;j < size2;++j)
			{
				arrayset[i, j] = copy.arrayset[i, j];
			}
		}
		return *this;
	}
	/*Mat& operator=(const Mat& copy)
	{

	}
	*/
	int main()
	{
		Mat w(2, 2);
		for (int i = 0;i < 2;++i)
			for (int j = 0;j < 2;++j)
				std::cout << w[i, j];
	}
};