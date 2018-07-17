#include <iostream>
#include <vector>
#include <fstream>
#include"entropy_range_coder.h"

int example1();
int example2();

int main()
{
	example1();
	//example2();
}

//自适应的区间编码 一定要用 Binary的方式读取写入的压缩文件
int example1()
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

	std::ofstream of("compressData.txt", std::ios_base::binary);
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
	std::ifstream ifs("compressData.txt", std::ios_base::binary);
	if (ifs)
	{
		int length = arc2.decodeStreamToCharVector(ifs, resData);
		ifs.close();
	}
	else
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

//static 区间的编码  一定要用 Binary的方式读取写入的压缩文件
int example2()
{
	StaticRangeCoder arc;

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

	std::ofstream of("compressData.txt", std::ios_base::binary);
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
	StaticRangeCoder arc2;
	std::ifstream ifs("compressData.txt", std::ios_base::binary);
	if (ifs)
	{
		int length = arc2.decodeStreamToCharVector(ifs, resData);
		ifs.close();
	}
	else
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