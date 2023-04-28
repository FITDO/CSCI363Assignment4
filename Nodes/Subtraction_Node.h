#ifndef _SUBTRACT_NODE_H_
#define _SUBTRACT_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Subtraction_Node
 * 
 * Node for subtracting two nodes (-).
 */
class Subtraction_Node : public Binary_Expr_Node
{
public:

    // Default Constructor
    Subtraction_Node (void);

    /**
     * Initializing constructor.
     * 
     * @param[in]       left        left node 
     * @param[in]       right       right node
     */
    Subtraction_Node (Expr_Node * left , Expr_Node * right);

    // Destructor
    ~Subtraction_Node (void);

    /**
     * Visitor to define behavior for Subtraction operations.
     * 
     * @param[in]       v           visitor 
     */
    void accept (Expr_Node_Visitor & v);

};

#include "Subtraction_Node.inl"

#endif