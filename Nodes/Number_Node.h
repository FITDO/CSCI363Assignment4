#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"

/**
 * @class Number_Node
 * 
 * Node to hold a number
 */
class Number_Node : public Expr_Node
{
public:
    
    /**
     * Initializing Constructor
     * 
     * @param       n               number 
     */
    Number_Node (int n);

    // Destructor
    virtual ~Number_Node (void);

    /**
     * Visitor to define behavior for Number operations.
     * 
     * @param[in]       v           visitor 
     */
    virtual void accept (Expr_Node_Visitor & v);

    /**
     * Return number.
     * 
     * @return          int         number   
     */
    int number (void) const;

private:

    // Number
    int n_;

};

#include "Number_Node.inl"

#endif