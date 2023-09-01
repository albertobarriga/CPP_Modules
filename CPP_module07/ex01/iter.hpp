#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename Y>
void iter(T *a, int len, void (*f)(Y))
{
	for (int i = 0; i < len; i++)
		f(a[i]);
}

template<typename T, typename Y>
void iter(T *a, int len, T (*f)(Y))
{
	for (int i = 0; i < len; i++)
		a[i] = f(a[i]);
}

#endif