#include <iostream>
#include <vector>
#include <fstream>
#include"entropy_range_coder.h"

int main()
{
	AdaptiveRangeCoder arc;
	//test data
	std::vector<char> inputByteVector;
	inputByteVector.push_back('i');
	inputByteVector.push_back(' ');
	inputByteVector.push_back('z');
	inputByteVector.push_back('j');
	inputByteVector.push_back('w');
	
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
	resData.resize(100);
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

	system("pause");
	return 0;
}
