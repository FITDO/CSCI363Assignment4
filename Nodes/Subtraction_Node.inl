

#include "Expr_Node_Visitor.h"

//
// accept (Expr_Node_Visitor &)
//
inline
void Subtraction_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Subtraction_Node (*this);
}