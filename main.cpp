#include <iostream>
#include <vector>
#include <fstream>
#include"entropy_range_coder.h"

int main()
{
	AdaptiveRangeCoder arc;

	//===========================================================

	//创建test data
	std::vector<char> inputByteVector;
	std::ifstream ifs2("english.txt");
	if (ifs2)
	{
		char c;
		while (ifs2 >> c)
		{
			inputByteVector.push_back(c);
		}
	}
	else
	{
		std::cout << "failed" << std::endl;
	}
	
	//===========================================================

	std::ofstream of("compressData.txt");
	if (of)
	{
		//arc.printZ();
		int length = arc.encodeCharVectorToStream(inputByteVector, of);
		of.close();
	}
	else
	{
		std::cout << "failed" << std::endl;
	}
	//========================================================

	std::vector<char> resData;
	resData.resize(inputByteVector.size());
	AdaptiveRangeCoder arc2;
	std::ifstream ifs("compressData.txt");
	if (ifs)
	{
		int length = arc2.decodeStreamToCharVector(ifs, resData);
		ifs.close();
	}else
	{
		std::cout << "failed" << std::endl;
	}

	//=========================================================
	//把解压出来的东西，放到文件里

	//创建test data
	
	std::ofstream ofs2("english_res.txt");
	if (ofs2)
	{
		for (int i = 0; i < resData.size(); i++)
		{
			ofs2 << resData[i];
		}
	}
	else
	{
		std::cout << "failed" << std::endl;
	}

	system("pause");
	return 0;
}
