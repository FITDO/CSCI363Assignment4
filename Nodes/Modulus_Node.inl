

#include "Expr_Node_Visitor.h"

//
// accept (Expr_Node_Visitor &)
//
inline
void Modulus_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Modulus_Node (*this);
}