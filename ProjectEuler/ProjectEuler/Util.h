#pragma once
template<typename T>
bool IsPalindrome(T p)
{
	std::string s = std::to_string(p);
	int l = s.size();

	for (int i = 0; i < l / 2; ++i)
	{
		if (s[i] != s[l - i - 1])
			return false;
	}

	return true;
}

// Sieve of Eratosthenes
// efficient for smaller primes
template <typename T>
bool IsPrime1(T p) 
{

	if (p == 2)
	{
		return true;
	}
	else if (p % 2 == 0 || p == 1)
	{
		return false;
	}
	else
	{
		for (T i = 3; i * i < p; i += 2)
		{
			if (p % i == 0)
				return false;
		}
	}
	return true;
}

//each prime other than 2 and 3 must be
//in the form 6k +- 1
template <typename T>
bool IsPrime2(T p)
{
	if (p == 2 || p == 3)
		return true;
	if (p % 2 == 0 || p % 3 == 0 || p == 1)
		return false;

	int div = 6;
	while ((div - 1) * div <= p)
	{
		if (p % (div - 1) == 0)
			return false;
		if (p % (div + 1) == 0)
			return false;
		
		div += 6;
	}

	return true;
}

template <typename T>
T NextPrime(T p)
{
	while (!IsPrime2(++++p))
	{ }
	return p;
}

template <typename T>
std::vector<T> GetFactors(T n)
{
	std::vector<T> factors;
	for (T i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			factors.push_back(i);
			factors.push_back(n / i);
		}
	}
	std::sort(factors.begin(), factors.end());

	return factors;
}

//template<typename T>
//std::vector<T> GetPrimeFactors(T n)
//{
//	std::vector<T> factors = GetFactors(n);
//	factors.erase(std::remove_if(factors.begin(),
//								factors.end(), 
//								[](T p) {	return !IsPrime(p);    }),
//				factors.end());
//
//	for (auto i : factors)
//		std::cout << i << " ";
//	return factors;
//}

template<typename T>
std::vector<T> GetPrimeFactors(T n)
{
	std::vector<T> primes;
	while (n % 2 == 0)
	{
		primes.push_back(2);
		n /= 2;
	}

	for (int i = 3; i * i <= n; i += 2)
	{
		// While i divides n, push i and divide n
		while (n%i == 0)
		{
			primes.push_back(i);
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2)
		primes.push_back(n);

	std::sort(primes.begin(), primes.end());

	return primes;

}