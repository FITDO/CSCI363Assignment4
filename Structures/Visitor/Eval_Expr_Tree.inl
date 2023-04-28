

#include "Number_Node.h"

//
// Visit_Number_Node (const Number_Node &)
//
inline
void Eval_Expr_Tree::Visit_Number_Node (const Number_Node & node)
{
    result_.push (node.number ());
}

//
// result
//
inline
int Eval_Expr_Tree::result (void)
{
    return result_.pop ();
}