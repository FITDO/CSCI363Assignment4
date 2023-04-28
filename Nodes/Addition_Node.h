#ifndef _ADDITION_NODE_H_
#define _ADDITION_NODE_H_

#include "Binary_Expr_Node.h"


/**
 * @class Addition_Node
 * 
 * Node for adding two nodes (+).
 */
class Addition_Node : public Binary_Expr_Node
{
public:

    // Default Constructor
    Addition_Node (void);

    /**
     * Initializing constructor.
     * 
     * @param[in]       left        left node 
     * @param[in]       right       right node
     */
    Addition_Node (Expr_Node * left , Expr_Node * right);

    // Destuctor
    ~Addition_Node (void);

    /**
     * Visitor to define behavior for Addition operations.
     * 
     * @param[in]       v           visitor 
     */
    void accept (Expr_Node_Visitor & v);

};

#include "Addition_Node.inl"

#endif