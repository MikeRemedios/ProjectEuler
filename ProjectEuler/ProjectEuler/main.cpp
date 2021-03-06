#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "Util.h"

/*
* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
* Find the sum of all the multiples of 3 or 5 below 1000.
*/
int Question1()
{
	int total = 0;
	for (int i = 3; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			total += i;
		}
	}
	return total;
}

/*
* Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
* 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
* By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/
int Question2()
{
	//even every third term
	int current = 1;
	int last = 0;
	int total = 0;
	while (current <= 4000000)
	{
		current += last;
		last = current - last;
		if (current % 2 == 0)
		{
			total += current;
		}
	}

	return total;
}

//What is the largest prime factor of the number 600851475143 ?
int Question3()
{
	int largestPrime = 0;
	for (auto i : GetFactors(600851475143))
	{
		if (IsPrime2(i))
		{
			if (i > largestPrime)
				largestPrime = i;
		}
	}
	return largestPrime;
}



//Find the largest palindrome made from the product of two 3-digit numbers.
int Question4()
{
	//go by each hundred probably?
	int i = 999;
	while (i >= 900)
	{
		for (int j = 999; j >= 900; --j)
		if (IsPalindrome(i * j))
		{
			return i * j;
		}
		--i;
	}
}

//What is the smallest positive number that is 
//evenly divisible by all of the numbers from 1 to 20?
unsigned long long Question5()
{
	//requires prime factorization of all numbers from 1-20 combined with no extras
	//ie 2 * 2 * 5 contains prime factors for 2, 4, 10, 20

	std::vector<int> primeFactors;
	for (int i = 2; i <= 20; ++i)
	{
		std::vector<int> p = GetPrimeFactors(i);
		std::set_difference(p.begin(), p.end(), primeFactors.begin(), primeFactors.end(),
			std::inserter(primeFactors, primeFactors.begin()));
		std::sort(primeFactors.begin(), primeFactors.end());
	}

	unsigned long long total = 1;
	for (auto i : primeFactors)
		total *= i;

	return total;
}

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
unsigned int Question6()
{
	unsigned int sumSquares = 0;
	unsigned int squareSums = 0;

	for (int i = 1; i <= 100; ++i)
	{
		squareSums += i;
		sumSquares += (i * i);
	}

	return squareSums * squareSums - sumSquares;
}

int main()
{
	std::cout << Question3() << std::endl;

	system("pause");
	return 0;
}