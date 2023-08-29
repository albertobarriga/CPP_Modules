#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *a, int len, void (*f)(T))
{
	for (int i = 0; i < len; i++)
		f(a[i]);
}

template<typename T>
void iter(T *a, int len, T (*f)(T))
{
	for (int i = 0; i < len; i++)
		a[i] = f(a[i]);
}

#endif