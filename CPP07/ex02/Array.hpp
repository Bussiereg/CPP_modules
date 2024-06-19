#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
    unsigned int _length;
    T *_arr;
public:
    Array<T>() : _length(0), _arr(new T()){}
    Array<T>(unsigned int nb) : _length(nb), _arr(new T[nb]) {}

    Array<T>(Array<T> const & rhs) : _length(rhs._length) {
        if (size() == 0)
            _arr = new T();
        else
            _arr = new T[size()];
        for ( unsigned int i = 0; i < _length; i++){
            _arr[i] = rhs._arr[i];
        }
    }

    Array<T> & operator=(Array<T> const & rhs) {
        if (this != &rhs){
            if (size() == 0)
                delete _arr;
            else                
                delete [] _arr;
            _length = rhs._length;
            _arr = new T[rhs._length];
            for (unsigned int j = 0; j < _length; j++){
                _arr[j] = rhs._arr[j];
            }
        }
        return *this;
    }

    ~Array<T>() {
        if (size() == 0)
            delete _arr;
        else
            delete [] _arr;
    }

    unsigned int size(void) const {return _length;}

    T & operator[](unsigned int nb) {
        if (nb >= _length) {
            throw std::out_of_range("Index out of range");
        }
        return _arr[nb];
    }
    
};

#endif