#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

class Expr_Node_Visitor;

/**
 * @class Expr_Node
 * 
 * Parent class of all nodes defines commen behevior for all
 * nodes.
 */
class Expr_Node
{
public:

    // Virtual Destructor
    virtual ~Expr_Node (void) = 0;

    /**
     * Visitor to define new operations without modification
     * to concrete classes.
     * 
     * @param[in]           v           visitor
     */
    virtual void accept (Expr_Node_Visitor & v) = 0;

protected:

    // Default Constructor
    Expr_Node (void);

};

#endif