

#include "Expr_Node_Visitor.h"

//
// number
//
inline
int Number_Node::number (void) const
{
    return this->n_;
}

//
// accept (Expr_Node_Visitor &)
//
inline
void Number_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Number_Node (*this);
}