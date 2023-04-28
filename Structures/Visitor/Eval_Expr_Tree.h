#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

#include "Stack.h"

/**
 * @class Eval_Expr_Tree
 *
 * A Visitor for performing all operations in a Expr_Node Tree.
 * Responsible for transversing the Tree/
 */
class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:

    // Default Constructor
    Eval_Expr_Tree (void);

    // Destructor
    virtual ~Eval_Expr_Tree (void);

    /**
     * Vist an Addition_Node and its children then add
     * 
     * @param[in]           node            Addition_Node
     */
    virtual void Visit_Addition_Node (const Addition_Node & node); 

    /**
     * Vist an Subtraction_Node and its children then subtract
     * 
     * @param[in]           node            Subtraction_Node
     */
    virtual void Visit_Subtraction_Node (const Subtraction_Node & node);

    /**
     * Vist an Multiplication_Node and its children then multiply
     * 
     * @param[in]           node            Multiplication_Node
     */
    virtual void Visit_Multiplication_Node (const Multiplication_Node & node);

    /**
     * Vist an Division_Node and its children then divide
     * 
     * @param[in]           node            Division_Node
     */
    virtual void Visit_Division_Node (const Division_Node & node);

    /**
     * Vist an Modulus_Node and its children then perfrom modulus
     * 
     * @param[in]           node            Modulus_Node
     */
    virtual void Visit_Modulus_Node (const Modulus_Node & node);

    /**
     * Vist an Number_Node and gets its value
     * 
     * @param[in]           node            Number_Node
     */
    virtual void Visit_Number_Node (const Number_Node & node);

    /**
     * Get the Result of a tree
     * 
     * @return              int             result
     */
    int result (void);

protected:

    // Stack for keeping track of values   
    Stack <int> result_;
    
};

#include "Eval_Expr_Tree.inl"

#endif