//
// Created by msalm on 2019/4/20.
//

#ifndef UNTITLED_TLV_H
#define UNTITLED_TLV_H

#include <cstddef>  // for size_t
#include <iostream>

class RangeError {
public:
    void exception()
    {
        std::cout << "exception" << "\n";
    }

};

size_t CountValues(const char * data, size_t size)
{
    size_t res = 0;
    try
    {
        for(size_t i=0;i<size;++i)
        {
            if (*data == '\0'|| *data == '\10'|| *data== '\13')
                ++res;
            ++data;
        }

        if (*data != '\0' && *data != '\10'&& *data!= '\13')
        {
            RangeError r;
            throw r;
        }
    }

    catch(RangeError r)
    {
        r.exception();
    }


    return res;
}


#endif //UNTITLED_TLV_H
