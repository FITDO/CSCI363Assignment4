

#include "Expr_Node_Visitor.h"

//
// accept (Expr_Node_Visitor &)
//
inline
void Multiplication_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Multiplication_Node (*this);
}