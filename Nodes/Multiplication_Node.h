#ifndef _MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Multiplication_Node
 * 
 * Node for multiplying two nodes (*).
 */
class Multiplication_Node : public Binary_Expr_Node
{
public:

    // Default Constructor
    Multiplication_Node (void);

    /**
     * Initializing constructor.
     * 
     * @param[in]       left        left node 
     * @param[in]       right       right node
     */
    Multiplication_Node (Expr_Node * left , Expr_Node * right);

    // Destructor
    ~Multiplication_Node (void);

    /**
     * Visitor to define behavior for Multiplication operations.
     * 
     * @param[in]       v           visitor 
     */
    void accept (Expr_Node_Visitor & v);
};

#include "Multiplication_Node.inl"

#endif