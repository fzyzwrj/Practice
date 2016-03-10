// 2016.3.9 by wrj
// src:°∂Ω£÷∏offer°∑√Ê ‘Ã‚22
// judge whether is pop order

#include <iostream>
#include <stack>

/// still be confused by some conditions, you should lookup sometimes
bool IsPopOrder(const int *pPush, const int *pPop, int length)
{
	bool isPossible = false;
	if (pPush == nullptr || pPop == nullptr || length == 0)
		return isPossible;
	std::stack<int> stackData;
	const int *pNextPush = pPush;
	const int *pNextPop = pPop;
	while (pNextPop - pPop < length)
	{
		// if top is not the pNextPop, continue push data
		while (stackData.empty() || stackData.top() != *pNextPop)
		{
			if (pNextPush - pPush == length)
				break;
			stackData.push(*pNextPush++);
		}

		// push all the data while still not right, break
		if (stackData.top() != *pNextPop)
			break;
		stackData.pop();
		pNextPop++;
	}
	if (stackData.empty() && pNextPush - pPush == length)
		isPossible = true;
	return isPossible;
}


int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int b1[] = {4, 5, 3, 2, 1};
	int b2[] = {4, 3, 5, 1, 2};
	std::cout << IsPopOrder(a, b1, 5) << std::endl;
	std::cout << IsPopOrder(a, b2, 5) << std::endl;
	return 0;

}
