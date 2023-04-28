#ifndef _PRINT_INORDER_EXPRESSION_H_
#define _PRINT_INORDER_EXPRESSION_H_

#include "Expr_Node_Visitor.h"

#include <iostream> // std::cout

/**
 * @class Print_Inorder_Expression
 * 
 * Visitor Pattern that prints the contents of a Expr_Node Tree
 */
class Print_Inorder_Expression : public Expr_Node_Visitor
{
public:

    // Default Construtor
    Print_Inorder_Expression (void);

    // Destrutor
    virtual ~Print_Inorder_Expression (void);
    
    /**
     * Visit a Addition Node and its children and print them in order
     * 
     * @param               node        Addition_Node
     */
    virtual void Visit_Addition_Node (const Addition_Node & node); 

    /**
     * Visit a Subtraction Node and its children and print them in order
     * 
     * @param               node        Subtraction_Node
     */
    virtual void Visit_Subtraction_Node (const Subtraction_Node & node);

    /**
     * Visit a Multiplication Node and its children and print them in order
     * 
     * @param               node        Multiplication_Node
     */
    virtual void Visit_Multiplication_Node (const Multiplication_Node & node);

    /**
     * Visit a Division Node and its children and print them in order
     * 
     * @param               node        Division_Node
     */
    virtual void Visit_Division_Node (const Division_Node & node);

    /**
     * Visit a Modulus Node and its children and print them in order
     * 
     * @param               node        Modulus_Node
     */
    virtual void Visit_Modulus_Node (const Modulus_Node & node);

    /**
     * Visit a Number Node and print its value
     * 
     * @param               node        Number_Node
     */
    virtual void Visit_Number_Node (const Number_Node & node);
    
};

#include "Print_Inorder_Expression.inl"

#endif