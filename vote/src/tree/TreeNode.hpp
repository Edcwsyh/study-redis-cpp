/*
    > File Name: TreeNode.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年09月22日 星期四 22时26分05秒
*/

#ifndef __TREENODE_EDC__
#define __TREENODE_EDC__

#include <algorithm>
#include <cstdint>
#include <array>
#include <memory>
#include <utility>

namespace Edc {

template<typename TVal, uint32_t MAX_SON_NODE_NUM>
class TreeNode {
//Type
public:
    typedef std::unique_ptr<TreeNode> PTreeNode;
    typedef TreeNode* poniter;
    
//Constant
public:
protected:
    
//Member Variables
protected:
    TVal m_oVal;
    std::array<PTreeNode, MAX_SON_NODE_NUM> m_oSonNodeList;
//Static Member Variables
protected:
    
//Member Function
public:
    TreeNode() = default;
    TreeNode( TVal&& oVal ) : m_oVal( std::forward<TVal>(oVal) ) {  }
    explicit TreeNode( const TreeNode& ) = default;
    explicit TreeNode( TreeNode&& ) = default;
    ~TreeNode() = default;
    TreeNode& operator=( const TreeNode& ) = default;
    TreeNode& operator=( TreeNode&& ) = default;
    bool operator==( TreeNode&& oNode ) const noexcept { return m_oVal == std::forward<TreeNode>(oNode).get_val(); }

    TVal& get_val() noexcept { return m_oVal; }
    template<typename TValParam>
    void set_val( TValParam&& oVal ) noexcept { m_oVal = std::forward<TValParam>(oVal); }
    // 获取子节点的数量
    uint32_t size() const noexcept;
    // 获取列表实体
    const std::array<PTreeNode, MAX_SON_NODE_NUM>& get_son_list() const noexcept { return m_oSonNodeList; }

    /**
     * @description earse 移除某一子节点
     *
     * @param pNode pNode为TreeNode的子节点
     */
    void earse( TreeNode* pNode ) noexcept;
    /**
     * @description earse 移除与oNode相同的节点  
     * 必须保证TVal实现operate==()
     *
     * @param oNode
     */
    void earse( TVal&& oVal ) noexcept;
    /**
     * @description earse_index 删除第uIdx个节点
     *
     * @param uIdx 节点索引值
     */
    void earse_index( uint64_t uIdx ) noexcept;
    /**
     * @description insert 新增一个子节点, 若uIdx位置已存在节点, 将导致其被删除  
     *
     * @param uIdx 子节点位置
     * @param pNode 需要新增的节点
     * @return 返回新增的子节点
     */
    TreeNode* insert( uint64_t uIdx, PTreeNode&& pNode ) noexcept;
    /**
     * @description insert 新增一个子节点  
     * 若uIdx位置已存在节点, 将导致其被删除  
     *
     * @param uIdx 子节点位置
     * @param oNode 需要新增的节点
     * @return 返回新增的子节点
     */
    TreeNode* insert( uint64_t uIdx, TreeNode&& oNode ) noexcept;
    /**
     * @description emplace 原位构造一个子节点
     * 若uIdx位置已存在节点, 将其val替换为oVal
     *
     * @param uIdx 构造位置
     * @param oVal 需要新增的节点
     * @return 返回新增的子节点
     */
    TreeNode* emplace( uint64_t uIdx, TVal&& oVal ) noexcept;
    /**
     * @description get_node 获取第uIdx个子节点
     *
     * @param uIdx 
     *
     * @return 
     */
    TreeNode* get_node( uint64_t uIdx ) noexcept;
    /**
     * @description release_node 释放第uIdx个节点
     *
     * @param uIdx
     *
     * @return 
     */
    PTreeNode release_node( uint64_t uIdx ) noexcept;

//Static Member Function
public:
    
};

// 获取子节点的数量
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
uint32_t TreeNode<TVal, MAX_SON_NODE_NUM>::size() const noexcept {
    uint32_t uTotalNum = 0;
    for ( auto& pNode : m_oSonNodeList ) {
        if ( pNode ) {
            ++uTotalNum;
        }
    }
    return uTotalNum;
}

// 移除子节点
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
void TreeNode<TVal, MAX_SON_NODE_NUM>::earse(TreeNode* pNode) noexcept {
    if ( pNode == nullptr ) {
        return;
    }
    for ( auto& pIterNode : m_oSonNodeList ) {
        if ( pIterNode.get() == pNode ) {
            pIterNode = nullptr;
            return;
        }
    }
}

// 移除与oNode相同的子节点
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
void TreeNode<TVal, MAX_SON_NODE_NUM>::earse(TVal&& oVal) noexcept {
    for ( auto& pNode : m_oSonNodeList ) {
        if ( pNode && pNode->get_val() == std::forward<TVal>(oVal) ) {
            pNode = nullptr;
        }
    }
}

// 删除第uIdx个节点
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
void TreeNode<TVal, MAX_SON_NODE_NUM>::earse_index(uint64_t uIdx) noexcept {
    if ( uIdx < MAX_SON_NODE_NUM && m_oSonNodeList[uIdx] ) {
        m_oSonNodeList[uIdx] = nullptr;
    }
}

// 新增一个子节点  
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
TreeNode<TVal, MAX_SON_NODE_NUM>* 
TreeNode<TVal, MAX_SON_NODE_NUM>::insert(uint64_t uIdx, PTreeNode&& pNode) noexcept {
    if ( uIdx >= MAX_SON_NODE_NUM ) {
        return nullptr;
    }
    PTreeNode& pNewNode = m_oSonNodeList[uIdx];
    pNewNode = std::move( pNode );
    return pNewNode.get();
}

// 新增一个子节点
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
TreeNode<TVal, MAX_SON_NODE_NUM>* 
TreeNode<TVal, MAX_SON_NODE_NUM>::insert(uint64_t uIdx, TreeNode&& oNode) noexcept {
    if ( uIdx >= MAX_SON_NODE_NUM ) {
        return nullptr;
    }
    PTreeNode& pNewNode = m_oSonNodeList[uIdx];
    if ( !pNewNode ) {
        pNewNode = std::make_unique<TreeNode>( std::forward<TreeNode>(oNode) );
    } else {
        *pNewNode = std::forward<TreeNode>(oNode);
    }
    return pNewNode.get();
}

// 原位构造一个子节点
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
TreeNode<TVal, MAX_SON_NODE_NUM>* 
TreeNode<TVal, MAX_SON_NODE_NUM>::emplace(uint64_t uIdx, TVal&& oVal) noexcept {
    if ( uIdx >= MAX_SON_NODE_NUM ) {
        return nullptr;
    }
    PTreeNode& pNewNode = m_oSonNodeList[uIdx];
    if ( !pNewNode ) {
        pNewNode = std::make_unique<TreeNode>( std::forward<TVal>(oVal) );
    } else {
        pNewNode->m_oVal = std::forward<TVal>(oVal);
    }
    return pNewNode.get();
}

// 获取第uIdx个子节点  
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
TreeNode<TVal, MAX_SON_NODE_NUM>* 
TreeNode<TVal, MAX_SON_NODE_NUM>::get_node(uint64_t uIdx) noexcept {
    if ( uIdx >= MAX_SON_NODE_NUM ) {
        return nullptr;
    }
    PTreeNode& pNewNode = m_oSonNodeList[uIdx];
    return pNewNode.get();
}

// 释放第uIdx个节点
template<typename TVal, uint32_t MAX_SON_NODE_NUM>
typename TreeNode<TVal, MAX_SON_NODE_NUM>::PTreeNode
TreeNode<TVal, MAX_SON_NODE_NUM>::release_node(uint64_t uIdx) noexcept {
    if ( uIdx >= MAX_SON_NODE_NUM ) {
        return nullptr;
    }
    return std::move( m_oSonNodeList[uIdx] );
}

}

#endif
