#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"

#include "Stack.h"

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

/**
 * @class Expr_Tree_Builder
 * 
 * Concrete Implementation of Builder Pattern. Responsible for
 * creating a Expr_Node tree.
 */
class Expr_Tree_Builder : public Expr_Builder
{
public:

    // Default Constructor
    Expr_Tree_Builder (void);

    // Desturctor
    ~Expr_Tree_Builder (void);
    
    /**
     * Prepares to make a new tree object
     * 
     */
    virtual void start_expression (void);


    /**
     * Creates a number node
     * 
     * @param[in]           n           number 
     */
    virtual void build_number (int n); 

    /**
     * Builds a Add Node
     * 
     */
    virtual void build_add_operator (void); 

    /**
     * Builds a Subtract Node
     * 
     */
    virtual void build_subtract_operator (void); 

    /**
     * Builds a Multiplication Node
     * 
     */
    virtual void build_multiplication_operator (void);

    /**
     * Builds a Division Node
     * 
     */
    virtual void build_division_operator (void);

    /**
     * Builds a Modulus Node
     * 
     */
    virtual void build_modulus_operator (void);


    /**
     * Prepares to deal with open parenthesis
     * 
     * @exception       std::runtime_error
     */
    virtual void build_open_parenthesis (void); 

    /**
     * Completes Current level of nodes and return to
     * previous level.
     * 
     * @exception       std::runtime_error
     */
    virtual void build_close_parenthesis (void); 

    /**
     * Get the finished expression
     * 
     * @return          Expr_Node * 
     */
    virtual Expr_Node * get_expression (void);

protected:

    /**
     * Recieve a Operator_Expr_Node and decide what to do
     * If current stack is empty add to stack
     * If top precedence is less than new node add to stack
     * If above false pop from stack until it can be added
     * 
     * @param[in]       node        New Node
     */
    virtual void advance (Operator_Expr_Node * node);
    
    /**
     * Delete All Nodes to prepare and reclaim memory
     * 
     */
    virtual void clear_memory (void);

private:

    // An Array of Stacks to keep track of parenthesis
    // and hold Operator_Expr_Nodes
    Array < Stack < Operator_Expr_Node * > * > level_;
    // Current Level (how many '(' have been hit)
    size_t current_;
    // Nodes with children and Number_Nodes
    Stack <Expr_Node *> com_;
};

#include "Expr_Tree_Builder.inl"

#endif