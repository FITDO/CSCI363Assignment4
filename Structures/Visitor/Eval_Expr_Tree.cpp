#include "Eval_Expr_Tree.h"

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

//
// Eval_Expr_Tree
//
Eval_Expr_Tree::Eval_Expr_Tree (void)
:result_ ()
{

}

//
// ~Eval_Expr_Tree
//
Eval_Expr_Tree::~Eval_Expr_Tree (void)
{

}

//
// Visit_Addition_Node (const Addition_Node &)
//
void Eval_Expr_Tree::Visit_Addition_Node (const Addition_Node & node)
{
    // COMMENT: To use the visitor correctly, you need to call the accept()
    // method on the left and right node pass "this" as the visitor.

    // FIXED: Visitor is now responsible for traversing the tree

    // Visit left_ and right_ nodes then pop 2 values off the stack and perform addition
    node.get_left()->accept (*this);
    node.get_right()->accept (*this);

    int n2 = result_.pop () , n1 = result_.pop ();
    result_.push (n1 + n2);
}

//
// Visit_Subtraction_Node (const Subtraction_Node &)
//
void Eval_Expr_Tree::Visit_Subtraction_Node (const Subtraction_Node & node)
{
    // COMMENT: To use the visitor correctly, you need to call the accept()
    // method on the left and right node pass "this" as the visitor.

    // FIXED: Visitor is now responsible for traversing the tree

    // Visit left_ and right_ nodes then pop 2 values off the stack and perform subtraction
    node.get_left()->accept (*this);
    node.get_right()->accept (*this);

    int n2 = result_.pop () , n1 = result_.pop ();
    result_.push (n1 - n2);
}

//
// Visit_Multiplication_Node (const Multiplication_Node &)
//
void Eval_Expr_Tree::Visit_Multiplication_Node (const Multiplication_Node & node)
{
    // COMMENT: To use the visitor correctly, you need to call the accept()
    // method on the left and right node pass "this" as the visitor.

    // FIXED: Visitor is now responsible for traversing the tree

    // Visit left_ and right_ nodes then pop 2 values off the stack and perform multiplication
    node.get_left()->accept (*this);
    node.get_right()->accept (*this);

    int n2 = result_.pop () , n1 = result_.pop ();
    result_.push (n1 * n2);
}

//
// Visit_Division_Node (const Division_Node &)
//
void Eval_Expr_Tree::Visit_Division_Node (const Division_Node & node)
{
    // COMMENT: To use the visitor correctly, you need to call the accept()
    // method on the left and right node pass "this" as the visitor.

    // FIXED: Visitor is now responsible for traversing the tree

    // Visit left_ and right_ nodes then pop 2 values off the stack and perform division
    // Throw error if n2 = 0
    node.get_left()->accept (*this);
    node.get_right()->accept (*this);

    int n2 = result_.pop () , n1 = result_.pop ();
    if ( n2 != 0 )
    {
        result_.push (n1 / n2);
    }
    else // n2 == 0
    {
        throw std::runtime_error("Division by Zero Error");
    }
}

//
// Visit_Modulus_Node (const Modulus_Node &)
//
void Eval_Expr_Tree::Visit_Modulus_Node (const Modulus_Node & node)
{
    // COMMENT: To use the visitor correctly, you need to call the accept()
    // method on the left and right node pass "this" as the visitor.

    // FIXED: Visitor is now responsible for traversing the tree

    node.get_left()->accept (*this);
    node.get_right()->accept (*this);

    // Visit left_ and right_ nodes then pop 2 values off the stack and perform modulus
    // Throw error if n2 = 0
    int n2 = result_.pop () , n1 = result_.pop ();
    if ( n2 != 0 )
    {
        result_.push (n1 % n2);
    }
    else // n2 == 0
    {
        throw std::runtime_error("Division by Zero Error");
    }
}

