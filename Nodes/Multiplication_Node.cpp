#include "Multiplication_Node.h"

//
// Multiplication_Node
//
Multiplication_Node::Multiplication_Node (void)
: Binary_Expr_Node (2 , nullptr , nullptr)
{

}

//
// Multiplication_Node (Expr_Node * , Expr_Node *)
//
Multiplication_Node::Multiplication_Node (Expr_Node * left , Expr_Node * right)
: Binary_Expr_Node (2 , left , right)
{

}

//
// ~Multiplication_Node
//
Multiplication_Node::~Multiplication_Node (void)
{
    
}