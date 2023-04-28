#include "Modulus_Node.h"

//
// Modulus_Node
//
Modulus_Node::Modulus_Node (void)
: Binary_Expr_Node (2 , nullptr , nullptr)
{

}

//
// Modulus_Node (Expr_Node * ,  Expr_Node *)
//
Modulus_Node::Modulus_Node (Expr_Node * left , Expr_Node * right)
: Binary_Expr_Node (2 , left , right)
{

}

//
// ~Modulus_Node
//
Modulus_Node::~Modulus_Node (void)
{
    
}