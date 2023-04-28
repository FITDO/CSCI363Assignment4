#ifndef _BINARY_OP_EXPR_NODE_H_
#define _BINARY_OP_EXPR_NODE_H_

#include "Operator_Expr_Node.h"

/**
 * @class Binary_Expr_Node
 * 
 * Abstract class used to define behavior for nodes with two
 * children.
 */
class Binary_Expr_Node : public Operator_Expr_Node
{
public:

    // Destructor
    virtual ~Binary_Expr_Node (void);

    /**
     * Set left_ and right_ using a stack<int>.
     * 
     * @param[in]       s           stack with Expr_Nodes
     * @return          true        method worked
     * @return          false       method failed
     */
    virtual bool set_children (Stack <Expr_Node *> & s);


    /**
     * Get left_
     * 
     * @return          Expr_Node * left_
     */
    virtual Expr_Node * get_left (void) const;

    /**
     * Get right_
     * 
     * @return          Expr_Node * right_
     */
    virtual Expr_Node * get_right (void) const;

protected:

    /**
     * Initializing constructor.
     * 
     * @param[in]       p           precedence
     * @param[in]       left        left node
     * @param[in]       right       left right
     */
    Binary_Expr_Node (int p , Expr_Node * left , Expr_Node * right);

    // left branch
    Expr_Node * left_;

    // right branch
    Expr_Node * right_;
};

#include "Binary_Expr_Node.inl"

#endif