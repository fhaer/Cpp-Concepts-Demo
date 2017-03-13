// example template
template<typename T>
void absoluteSum(T data[], const int N, T &result) {
	T sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (data[i] >= 0)
			sum = sum + data[i];
		else
			sum = sum - data[i];
  	}
  	result = sum;
}

// template usage
void f() {
	int iArray[] = {-3, 4, 5};
	int iResult;
	absoluteSum(iArray, 3, iResult);

	double dArray[] = {3.3, -4.4};
	double dResult;
	absoluteSum(dArray, 2, dResult);
}

// signature of the absoluteSum template to constrain the type T
auto concept Assignable<typename T>       { T& operator=(T& x, T y); };
auto concept IntConstructible<typename T> { T::T(int);               };
auto concept Addable<typename T>          { T operator+(T x, T y);   };
auto concept Subtractable<typename T>     { T operator-(T x, T y);   };
auto concept GreaterEqualsComparable<typename T>
                                        { bool operator>=(T x, T y); };
template<std::CopyConstructible T>
requires Assignable<T>, IntConstructible<T>, Addable<T>,
  Subtractable<T>, GreaterEqualsComparable<T>
void absoluteSum(T data[], const int N, T &result)


