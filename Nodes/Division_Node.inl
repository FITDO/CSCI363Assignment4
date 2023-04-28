

#include "Expr_Node_Visitor.h"

//
// accept (Expr_Node_Visitor &)
//
inline 
void Division_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Division_Node (*this);
}