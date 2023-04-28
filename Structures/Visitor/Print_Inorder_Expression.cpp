#include "Print_Inorder_Expression.h"

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

//
// Print_Inorder_Expression
//
Print_Inorder_Expression::Print_Inorder_Expression (void)
{

}

//
// ~Print_Inorder_Expression
//
Print_Inorder_Expression::~Print_Inorder_Expression (void)
{

}

//
// Visit_Addition_Node (const Addition_Node &)
//
void Print_Inorder_Expression::Visit_Addition_Node (const Addition_Node & node)
{
    // Vist its left child then print "+ " and enter its right child
    node.get_left()->accept (*this);
    std::cout << "+ ";
    node.get_right()->accept (*this);
}

//
// Visit_Subtraction_Node (const Subtraction_Node &)
//
void Print_Inorder_Expression::Visit_Subtraction_Node (const Subtraction_Node & node)
{
    // Vist its left child then print "- " and enter its right child
    node.get_left()->accept (*this);
    std::cout << "- ";
    node.get_right()->accept (*this);
}

//
// Visit_Multiplication_Node (const Multiplication_Node &)
//
void Print_Inorder_Expression::Visit_Multiplication_Node (const Multiplication_Node & node)
{
    // Vist its left child then print "* " and enter its right child
    node.get_left()->accept (*this);
    std::cout << "* ";
    node.get_right()->accept (*this);
}

//
// Visit_Division_Node (const Division_Node &)
//
void Print_Inorder_Expression::Visit_Division_Node (const Division_Node & node)
{
    // Vist its left child then print "/ " and enter its right child
    node.get_left()->accept (*this);
    std::cout << "/ ";
    node.get_right()->accept (*this);
}

//
// Visit_Modulus_Node (const Modulus_Node &)
//
void Print_Inorder_Expression::Visit_Modulus_Node (const Modulus_Node & node)
{
    // Vist its left child then print "% " and enter its right child
    node.get_left()->accept (*this);
    std::cout << "% ";
    node.get_right()->accept (*this);
}

