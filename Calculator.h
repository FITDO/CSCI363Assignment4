#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

#include "Eval_Expr_Tree.h"
#include "Expr_Tree_Builder.h"

/**
 * @class Calculator
 * 
 * A Facade to handle the complexites of make a Expr_Node tree
 * and getting an answer
 */
class Calculator
{
public:

    // Default Constructor
    Calculator (void);

    // Destructor
    virtual ~Calculator (void);

    /**
     * Runs The Calculator, uses a for loop to keep recieveing inputs
     * Has Error Catching, types "QUIT" to stop
     */
    virtual void run (void);

protected:

    /**
     * Turns a string into a Expr_Node * tree and returns it
     * 
     * @param[in]           infix           equation 
     * @return              Expr_Node *     Expr Node Tree
     */
    virtual Expr_Node * infix_to_tree (std::string & infix);

    /**
     * Takes a Expr Node Tree and returns a result
     * 
     * @param[in]           tree            Expr Node Tree 
     * @return              int             result
     */
    virtual int evaluate (Expr_Node * tree);

private:

    // Used to build the Expr Node Tree
    Expr_Tree_Builder builder_;
    
    // Used to evaluate the tree
    Eval_Expr_Tree eval_;

};

#endif