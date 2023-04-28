#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Division_Node
 * 
 * Node for dividing two nodes (/).
 */
class Division_Node : public Binary_Expr_Node
{
public:

    // Default Constructor
    Division_Node (void);

    /**
     * Initializing constructor.
     * 
     * @param[in]       left        left node 
     * @param[in]       right       right node
     */
    Division_Node (Expr_Node * left , Expr_Node * right);

    // Destuctor
    ~Division_Node (void);

    /**
     * Visitor to define behavior for Division operations.
     * 
     * @param[in]       v           visitor 
     */
    void accept (Expr_Node_Visitor & v);
};

#include "Division_Node.inl"

#endif