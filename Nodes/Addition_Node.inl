

#include "Expr_Node_Visitor.h"

//
// accept (Expr_Node_Visitor &)
//
inline
void Addition_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Addition_Node (*this);
}