//
// Created by 10578 on 2021/4/20.
//

#ifndef __CODE_LIBRARY_ISPRIME_H__
#define __CODE_LIBRARY_ISPRIME_H__

template<unsigned p, unsigned d>
struct DoIsPrime{
    static constexpr bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
};

template<unsigned p>
struct DoIsPrime<p, 2>{
    static constexpr bool value = (p % 2 != 0);
};

template<unsigned p>
struct IsPrime{
    static constexpr bool value = DoIsPrime<p, p / 2>::value;
};

template<>
struct IsPrime<0>{
    static constexpr bool value = false;
};

template<>
struct IsPrime<1>{
    static constexpr bool value = false;
};

template<>
struct IsPrime<2>{
    static constexpr bool value = true;
};

template<>
struct IsPrime<3>{
    static constexpr bool value = true;
};


#endif //__CODE_LIBRARY_ISPRIME_H__
