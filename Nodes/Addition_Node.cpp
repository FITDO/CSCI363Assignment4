#include "Addition_Node.h"

//
// Addition_Node
//
Addition_Node::Addition_Node (void)
:  Binary_Expr_Node (1 , nullptr , nullptr)
{

}

//
// Addition_Node (Expr_Node * , Expr_Node *)
//
Addition_Node::Addition_Node (Expr_Node * left , Expr_Node * right)
: Binary_Expr_Node (1 , left , right)
{

}

//
// ~Addition_Node
//
Addition_Node::~Addition_Node (void)
{

}