#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Expr_Node.h"

/**
 * @class Expr_Builder
 * 
 * Template Class for defining methods for concrete
 * implementations of Builder patterns.
 */
class Expr_Builder
{
public:

    /**
     * Starts the process of building a Expr_Tree
     * 
     */
    virtual void start_expression (void) = 0;


    /**
     * Builds a Number Node
     * 
     * @param[in]           n 
     */
    virtual void build_number (int n) = 0; 

    /**
     * Builds a Add Node
     * 
     */
    virtual void build_add_operator (void) = 0; 

    /**
     * Builds a Subtract Node
     * 
     */
    virtual void build_subtract_operator (void) = 0; 

    /**
     * Builds a Multiplication Node
     * 
     */
    virtual void build_multiplication_operator (void) = 0;

    /**
     * Builds a Division Node
     * 
     */
    virtual void build_division_operator (void) = 0;

    /**
     * Builds a Modulus Node
     * 
     */
    virtual void build_modulus_operator (void) = 0;


    /**
     * Decides what to do with an open parenthesis
     * 
     */
    virtual void build_open_parenthesis (void) = 0; 

    /**
     * Decides what to do with an closed parenthesis
     * 
     */
    virtual void build_close_parenthesis (void) = 0; 


    /**
     * Returns the completed Expr_Node tree
     * 
     * @return          Expr_Node *     Expr Node Tree
     */
    virtual Expr_Node * get_expression (void) = 0;
    
protected:

    // Default Constructor
    Expr_Builder (void);

    // Destructor
    virtual ~Expr_Builder (void);

};

#endif