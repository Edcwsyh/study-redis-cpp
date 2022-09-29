/*
    > File Name: PrefixTree.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年09月19日 星期一 21时11分33秒
*/

#ifndef __PREFIXTREE_EDC__
#define __PREFIXTREE_EDC__

#include "CharAssociater.hpp"
#include "TreeNode.hpp"
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace Edc {

// 前缀树
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
class PrefixTree {
//Type
public:
    typedef CharAssociater<TChar, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER> Associater;
    typedef TreeNode<TVal, MAX_ASSOCIATE_VALUE> Node;
    
//Constant
public:
    enum ErrorCode {
        ERR_NO_ASSOCIATER = -1,     // 未初始化关联器
        ERR_NO_ASSOCIATE_VAL = -2,  // 未找到关联值
        ERR_NO_ASSOCIATE_CHAR = -3, // 未找到关联字符
        ERR_INSERT_FAIL = -4,       // 新增节点失败
    };
protected:
    
//Member Variables
protected:
    std::unique_ptr<Associater> m_pAssociater;
    Node m_oRootNode;
    
//Static Member Variables
protected:
    
//Member Function
public:
    PrefixTree() = default;
    PrefixTree( std::unique_ptr<Associater>&& pAssociater ) : m_pAssociater( std::move( pAssociater ) ) {  }
    PrefixTree( const PrefixTree& );
    PrefixTree( PrefixTree&& ) = default;
    ~PrefixTree() = default;
    PrefixTree& operator=( const PrefixTree& );
    PrefixTree& operator=( PrefixTree&& ) = default;

    // 获取关联器 
    Associater& get_associater() noexcept;

    // 设置关联器
    void set_associater( Associater&& oAssciater ) noexcept;

    /**
     * @description insert 插入一个字符串
     *
     * @param str
     */
    int insert( const std::basic_string<TChar>& str, TVal&& oVal ) noexcept;
    /**
     * @description match_all 匹配所有前缀为prefix的字符串
     *
     * @param prefix
     *
     * @return 
     */
    std::vector<std::basic_string<TChar>> match_all( const std::basic_string<TChar>& prefix ) noexcept;
    /**
     * @description find 找到str对应的节点
     *
     * @param str
     *
     * @return 
     */
    Node* find( const std::basic_string<TChar>& str ) noexcept;
    /**
     * @description get_val 返回str对应节点的值
     *
     * @param str
     *
     * @return 
     */
    TVal get_val( const std::basic_string<TChar>& str ) noexcept;
protected : 
    /**
     * @description match_all 底层匹配实现
     *
     * @param pNode
     * @param oMacthList
     */
    void match_all( const std::basic_string<TChar>& str, const Node& pNode, std::vector<std::basic_string<TChar>>& oMacthList ) const noexcept;

//Static Member Function
public:
    
};

// 拷贝构造
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::PrefixTree(const PrefixTree& obj) {
    m_oRootNode = obj.m_oRootNode;
    m_pAssociater = std::make_unique<Associater>( *obj.m_pAssociater.get() );
}

// 复制构造
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>& 
PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::operator=(const PrefixTree& obj) {
    m_oRootNode = obj.m_oRootNode;
    m_pAssociater = std::make_unique<Associater>( *obj.m_pAssociater.get() );
}


// 插入一个字符串
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
int PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::insert(const std::basic_string<TChar>& str, TVal&& oVal) noexcept {
    if ( !m_pAssociater  ) {
        return ERR_NO_ASSOCIATER;
    }
    Node* pNode = &m_oRootNode;
    auto pIter = str.begin(), pEnd = str.end() - 1;
    for ( ;pIter != pEnd; ++pIter ) {
        uint64_t uMapVal = m_pAssociater->get_val_by_obj( *pIter );
        if ( uMapVal == Associater::INVALID_VAL  ) {
            return ERR_NO_ASSOCIATE_VAL;
        }
        Node* pNextNode = pNode->get_node( uMapVal );
        if ( !pNextNode ) {
            if ( !( pNextNode = pNode->insert( uMapVal, Node() ) ) ) {
                return ERR_INSERT_FAIL;
            }
        }
        pNode = pNextNode;
    }
    uint64_t uMapVal = m_pAssociater->get_val_by_obj( *pIter );
    if ( uMapVal == Associater::INVALID_VAL  ) {
        return ERR_NO_ASSOCIATE_VAL;
    }
    if ( !( pNode->insert( uMapVal, Node( std::forward<TVal>( oVal ) ) ) ) ) {
        return ERR_INSERT_FAIL;
    }
    return 0;
}

// 匹配所有前缀为prefix的字符串
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
std::vector<std::basic_string<TChar>>
PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::match_all(const std::basic_string<TChar>& prefix) noexcept {
    std::vector<std::basic_string<TChar>> oMatchList;
    Node* pNode = find(prefix);
    if ( !pNode ) {
        return oMatchList;
    }
    match_all( prefix, *pNode, oMatchList );
    return oMatchList;
}

// 底层匹配实现
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
void PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::match_all(const std::basic_string<TChar>& str, const Node& oNode, std::vector<std::basic_string<TChar>>& oMacthList) const noexcept {
    uint32_t uSonNodeNum = 0;
    uint32_t uNodeIdx = 0;
    for ( auto& pNode : oNode.get_son_list() ) {
        if ( pNode ) {
            std::basic_string<TChar> sNewStr = str + m_pAssociater->get_obj_by_val( uNodeIdx );
            match_all( sNewStr, *( pNode.get() ), oMacthList );
            ++uSonNodeNum;
        }
        ++uNodeIdx;
    }
    if ( !uSonNodeNum ) {
        oMacthList.push_back( str );
    }
}

// 找到str对应的节点
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
TreeNode<TVal, MAX_ASSOCIATE_VALUE>* 
PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::find(const std::basic_string<TChar>& str) noexcept {
    Node* pTarget = &m_oRootNode;
    for ( auto c : str ) {
        uint64_t uMapVal = m_pAssociater->get_val_by_obj( c );
        if ( uMapVal == Associater::INVALID_VAL  ) {
            return nullptr;
        }
        if ( !( pTarget = pTarget->get_node( uMapVal ) ) ) {
            return nullptr;
        }
    }
    return pTarget;
}

// 返回str节点对应的值
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
TVal PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::get_val(const std::basic_string<TChar>& str) noexcept {
    Node* pTarget = find( str );
    TVal oVal;
    if ( pTarget ) {
        oVal = pTarget->get_val();
    }
    return oVal;
}

// 设置关联器
template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
void PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::set_associater(Associater&& oAssciater) noexcept {
    if ( !m_pAssociater ) {
        m_pAssociater = std::make_unique<Associater>( std::forward<Associater>( oAssciater ) );
    } else {
        *m_pAssociater = std::forward<Associater>(oAssciater);
    }
}

template<typename TChar, typename TVal, uint32_t MAX_ASSOCIATE_VALUE, uint32_t MAX_ASSOCIATE_CHARACTER>
typename PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::Associater& 
PrefixTree<TChar, TVal, MAX_ASSOCIATE_VALUE, MAX_ASSOCIATE_CHARACTER>::get_associater() noexcept {
    if ( !m_pAssociater ) {
        m_pAssociater = std::make_unique<Associater>();
    }
    return *m_pAssociater;
}

}

#endif
