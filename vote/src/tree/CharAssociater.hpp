/*
    > File Name: CharAssociater.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年09月19日 星期一 22时05分23秒
*/

#ifndef __CHARASSOCIATER_EDC__
#define __CHARASSOCIATER_EDC__

// #include "edclib/tools/AssociateTool/NumberAssociater.hpp"
#include "NumberAssociater.hpp"
#include <cstddef>
#include <array>
#include <cstdint>

namespace Edc {

// 字符关联器 : 将某个字符同某个数字关联起来
// TChar : char wchar_t
template<typename TChar, uint64_t MAX_ASSOCIATE_VALUE, uint64_t MAX_ASSOCIATE_CHARACTER>
class CharAssociater : public NumberAssociater<TChar>{
//Type
public:
    static constexpr uint64_t INVALID_VAL = MAX_ASSOCIATE_VALUE + 1;
    static constexpr uint64_t INVALID_CHAR = MAX_ASSOCIATE_CHARACTER + 1;
    
//Constant
public:
protected:
    
//Member Variables
protected:
    std::array<uint64_t, MAX_ASSOCIATE_CHARACTER> m_oCharMap;
    std::array<TChar, MAX_ASSOCIATE_VALUE> m_oNumberMap;
    
//Static Member Variables
protected:
    
//Member Function
public:
    CharAssociater() = default;
    CharAssociater( const CharAssociater& ) = default;
    CharAssociater( CharAssociater&& ) = default;
    ~CharAssociater() = default;
    CharAssociater& operator=( const CharAssociater& ) = default;
    CharAssociater& operator=( CharAssociater&& ) = default;

    // 获取对象的关联值
    uint64_t get_val_by_obj( const TChar& obj ) const noexcept override;
    // 获取某个值的关联对象
    virtual const TChar& get_obj_by_val( uint64_t ullVal ) const noexcept override;
    // 将两个对象关联起来
    virtual bool associate( const TChar& character, const uint64_t& ullNum ) noexcept override;
    // 获取关联值的最大值
    constexpr uint64_t get_max_val() const noexcept { return MAX_ASSOCIATE_VALUE; };
//Static Member Function
public:
    
};

// 获取对象的关联值
template<typename TChar, uint64_t MAX_ASSOCIATE_VALUE, uint64_t MAX_ASSOCIATE_CHARACTER>
uint64_t CharAssociater<TChar, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::get_val_by_obj(const TChar& obj) const noexcept {
    if ( obj >= MAX_ASSOCIATE_CHARACTER )
    {
        return INVALID_VAL;
    }
    return m_oCharMap[obj];
}

// 获取某个值的关联对象
template<typename TChar, uint64_t MAX_ASSOCIATE_VALUE, uint64_t MAX_ASSOCIATE_CHARACTER>
const TChar& CharAssociater<TChar, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::get_obj_by_val(uint64_t ullVal) const noexcept {
    static TChar oStaticVal = INVALID_CHAR;
    if ( ullVal >= MAX_ASSOCIATE_VALUE )
    {
        return oStaticVal;
    }
    return m_oNumberMap[ullVal];
}

// 将两个对象关联起来
template<typename TChar, uint64_t MAX_ASSOCIATE_VALUE, uint64_t MAX_ASSOCIATE_CHARACTER>
bool CharAssociater<TChar, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::associate(const TChar& character, const uint64_t& ullNum) noexcept {
    if ( character >= MAX_ASSOCIATE_CHARACTER || ullNum >= MAX_ASSOCIATE_VALUE )
    {
        return false;
    }
    m_oNumberMap[ullNum] = character;
    m_oCharMap[character] = ullNum;
    return true;
}

}

#endif
