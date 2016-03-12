// 2016.3.9 by wrj
// src: JianZhi Offer, problem 10
// Counts how many ones in a number

#include <iostream>

int CountOnes(int n)
{
	int cnt = 0;
	while (n)
	{
		++cnt;
        n = n & (n - 1);    // convert the rightest one into zero
	}
	return cnt;
}

int main()
{
    std::cout << CountOnes(16) << std::endl;
    std::cout << CountOnes(17) << std::endl;
    std::cout << CountOnes(18) << std::endl;
    std::cout << CountOnes(-1) << std::endl;
    std::cout << CountOnes(255) << std::endl;
}

