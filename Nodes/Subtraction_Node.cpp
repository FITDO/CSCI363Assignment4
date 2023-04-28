#include "Subtraction_Node.h"

//
// Subtraction_Node
//
Subtraction_Node::Subtraction_Node (void)
: Binary_Expr_Node (1 , nullptr , nullptr)
{

}

//
// Subtraction_Node (Expr_Node * , Expr_Node *)
//
Subtraction_Node::Subtraction_Node (Expr_Node * left , Expr_Node * right)
: Binary_Expr_Node (1 , left , right)
{

}

//
// ~Subtraction_Node
//
Subtraction_Node::~Subtraction_Node (void)
{
    
}