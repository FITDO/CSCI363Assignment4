#ifndef _UNARY_OP_EXPR_NODE_H_
#define _UNARY_OP_EXPR_NODE_H_

#include "Operator_Expr_Node.h"

/**
 * @class Unary_Expr_Node
 * 
 * Abstract class used to define behavior for nodes with one
 * child.
 */
class Unary_Expr_Node : public Operator_Expr_Node
{
public:

    // Desturctor
    virtual ~Unary_Expr_Node (void) = 0;

    /**
     * Set child_ using a stack<int>.
     * 
     * @param[in]       s           stack with Expr_Nodes
     * @return          true        method worked
     * @return          false       method failed
     */
    virtual bool set_children (Stack <Expr_Node *> & s);

    /**
     * Get child_
     * 
     * @return          Expr_Node * child_
     */
    virtual Expr_Node * get_child (void) const;

protected:

    /**
     * Initializing constructor.
     * 
     * @param           p           precedence
     * @param           child       child_
     */
    Unary_Expr_Node (int p , Expr_Node * child);

    // Child Node
    Expr_Node * child_;
};

#include "Unary_Expr_Node.inl"

#endif