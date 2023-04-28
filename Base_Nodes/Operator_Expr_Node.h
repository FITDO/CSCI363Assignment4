#ifndef _OPERATOR_EXPR_NODE_H_
#define _OPERATOR_EXPR_NODE_H_

#include "Expr_Node.h"

#include <stdexcept> // std::runtime_error

#include "Stack.h"

/**
 * @class Operator_Expr_Node
 * 
 * Abstract class used to define behavior for operator Nodes.
 */
class Operator_Expr_Node : public Expr_Node
{
public:

    // Destructor
    virtual ~Operator_Expr_Node (void) = 0;

    /**
     * Returns the precedence of the class
     * 
     * @return          int       precedence
     */
    virtual int precedence (void) const;


    /**
     * Allows the child classes to define their children
     * Returns true if method works returns false otherwise.
     * 
     * @param           s         Stack with Expr_Nodes
     * @return          true 
     * @return          false 
     */
    virtual bool set_children (Stack <Expr_Node *> & s) = 0;

protected:

    /**
     * Initializing constructor.
     * 
     * @param[in]       p       precedence 
     */
    Operator_Expr_Node (int p);

private:
    
    // Precedence for the class
    // Should be defined by the concrete class
    int p_;
};

#include "Operator_Expr_Node.inl"

#endif