#ifndef _MODULUS_NODE_H_
#define _MODULUS_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Modulus_Node
 * 
 * Node for performing modulus on two nodes (%).
 */
class Modulus_Node : public Binary_Expr_Node
{
public:

    // Default Constructor
    Modulus_Node (void);

    /**
     * Initializing constructor.
     * 
     * @param[in]       left        left node 
     * @param[in]       right       right node
     */
    Modulus_Node (Expr_Node * left , Expr_Node * right);

    // Destructor
    ~Modulus_Node (void);

    /**
     * Visitor to define behavior for Modulus operations.
     * 
     * @param[in]       v           visitor 
     */
    void accept (Expr_Node_Visitor & v);

};

#include "Modulus_Node.inl"

#endif