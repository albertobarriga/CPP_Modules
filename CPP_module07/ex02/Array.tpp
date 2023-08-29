#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(): _array(0), _size(0) {

}

template <typename T>
Array<T>::Array(unsigned int n): _size(n) {
	_array = new T[_size]();
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T>::Array(Array const &copy): _size(copy._size) {
	_array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i]; 
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const &copy) {
	this->_size = copy._size;
	_array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template <typename T>
const char *Array<T>::OutRange::what() const throw()
{
	return ("This index is out of range");
}

template <typename T>
T	&Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw Array::OutRange();
	else
		return (_array[index]);
}

#endif