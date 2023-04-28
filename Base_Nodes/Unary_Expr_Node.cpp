#include "Unary_Expr_Node.h"

//
// Unary_Expr_Node (int , child)
//
Unary_Expr_Node::Unary_Expr_Node (int p , Expr_Node * child)
: Operator_Expr_Node (p) ,
 child_ (child)
{

}

//
// ~Unary_Expr_Node
//
Unary_Expr_Node::~Unary_Expr_Node (void)
{
    delete child_;
}

//
// set_children (Stack<Expr_Node *> &)
//
bool Unary_Expr_Node::set_children (Stack <Expr_Node *> & s)
{
    if (!this->child_ && s.size () > 1)
    {
        this->child_ = s.pop ();
        return true;
    }
    return false;
}