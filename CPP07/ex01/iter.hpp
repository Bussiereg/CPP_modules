#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *ad, unsigned long sz, void (*fct)(T &)){
    for (unsigned long i = 0; i < sz; i++){
        fct(ad[i]);
    }
} 

#endif