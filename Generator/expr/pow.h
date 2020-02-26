//
// Created by maxlun on 12/26/19.
//

#ifndef PARSING_POW_H
#define PARSING_POW_H

inline int32_t pow1 (uint32_t a, uint32_t b) {
    int32_t num = a;
    int32_t result = 1;
    while ( b > 0 ){
        if ( b & 1 == 1){
            result *= num;
        }
        num *= num;
        b >>=1;
    }
    return result;
}

#endif //PARSING_POW_H
