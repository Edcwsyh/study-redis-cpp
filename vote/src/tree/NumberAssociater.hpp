/*
    > File Name: NumberAssociater.hpp 数字关联器
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年09月19日 星期一 11时50分57秒
*/

#ifndef __NUMBERASSOCIATER_EDC__
#define __NUMBERASSOCIATER_EDC__

#include <cstdint>
#include "BaseAssociater.hpp"

namespace Edc {

// 数字关联器 : 将某个对象关联为某个数字
template <typename T>
class NumberAssociater : public BaseAssociater<T, uint64_t>{
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
protected:
    // 屏蔽原有的获取接口, 只允许父类调用
    virtual const T& get_type1_val( uint64_t& ullVal ) const noexcept override { 
        return get_obj_by_val( ullVal );
    };
    virtual const uint64_t& get_type2_val( T& obj ) const noexcept override {
        static uint64_t val;
        val = get_val_by_obj( obj );
        return val;
    };
    
//Static Member Variables
protected:
    
//Member Function
public:
    NumberAssociater() = default;
    explicit NumberAssociater( const NumberAssociater& ) = default;
    explicit NumberAssociater( NumberAssociater&& ) = default;
    ~NumberAssociater() = default;
    NumberAssociater& operator=( const NumberAssociater& ) = default;
    NumberAssociater& operator=( NumberAssociater&& ) = default;

    // 获取对象的关联值
    virtual uint64_t get_val_by_obj( const T& obj ) const noexcept = 0;
    // 获取某个值的关联对象
    virtual const T& get_obj_by_val( uint64_t ullVal ) const noexcept = 0;
//Static Member Function
public:
    
};

}

#endif
