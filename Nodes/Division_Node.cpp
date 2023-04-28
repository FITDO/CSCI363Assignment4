#include "Division_Node.h"

//
// Division_Node
//
Division_Node::Division_Node (void)
:  Binary_Expr_Node (2 , nullptr , nullptr)
{

}

//
// Division_Node (Expr_Node * , Expr_Node *)
//
Division_Node::Division_Node (Expr_Node * left , Expr_Node * right)
: Binary_Expr_Node (2 , left , right)
{

}

//
// ~Division_Node
//
Division_Node::~Division_Node (void)
{
    
}