/*
    > File Name: BaseAssociater.hpp 关联器基类
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年09月19日 星期一 21时40分56秒
*/

#ifndef __BASE_ASSOCIATEOR_EDC__
#define __BASE_ASSOCIATEOR_EDC__

namespace Edc  {

// 关联器基类
template <typename T1, typename T2>
class BaseAssociater {
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
protected:
    
//Static Member Variables
protected:
    
//Member Function
public:
    BaseAssociater() = default;
    explicit BaseAssociater( const BaseAssociater& ) = default;
    explicit BaseAssociater( BaseAssociater&& ) = default;
    ~BaseAssociater() = default;
    BaseAssociater& operator=( const BaseAssociater& ) = default;
    BaseAssociater& operator=( BaseAssociater&& ) = default;

    // 获取T2的关联对象T1
    virtual const T1& get_type1_val( T2& ) const noexcept = 0;
    // 获取T1的关联对象T2
    virtual const T2& get_type2_val( T1& ) const noexcept = 0;
    // 将两个对象关联起来
    virtual bool associate( const T1&, const T2& ) noexcept = 0;
//Static Member Function
public:
    
};
}

#endif

