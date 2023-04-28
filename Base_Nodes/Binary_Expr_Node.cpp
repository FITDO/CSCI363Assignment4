#include "Binary_Expr_Node.h"

//
// Binary_Expr_Node (int , Expr_Node * , Expr_Node *)
//
Binary_Expr_Node::Binary_Expr_Node (int p , Expr_Node * left , Expr_Node * right)
: Operator_Expr_Node (p) ,
 left_ (left) ,
 right_ (right)
{

}

//
// ~Binary_Expr_Node
//
Binary_Expr_Node::~Binary_Expr_Node (void)
{
    delete this->left_;
    delete this->right_;
}

//
// set_children (Stack<int>)
//
bool Binary_Expr_Node::set_children (Stack <Expr_Node *> & s)
{
    // Confirm that both branches are null and stack has enough Nodes
    if (!this->left_ && !this->right_ && s.size () > 1)
    {
        this->right_ = s.pop ();
        this->left_ = s.pop ();
        return true;
    }
    return false;
}