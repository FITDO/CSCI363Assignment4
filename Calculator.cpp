#include "Calculator.h"

#include <sstream> // stringstream

//
// Calculator
//
Calculator::Calculator (void)
: builder_ () ,
  eval_ ()
{

}

//
// ~Calculator
//
Calculator::~Calculator (void)
{

}

// COMMENT: Do not go from infix to postfix then to tree. Instead,
// go directly from infix to tree. The extra step is not necessary.
// Moreover, with the builder pattern, the client should not be aware
// of how to “construct” the product. With you use this approach, you
// are making the client aware and responsible for constructing the
// expression tree.

// FIXED: Professor said to disregard this comment. No changes were made.

//
// infix_to_tree (std::string &)
//
Expr_Node * Calculator::infix_to_tree (std::string & infix)
{
    // Use a stringstream to tokenize the infix, while loop,
    // and builder to generate a Expr_Node Tree
    std::istringstream input(infix);
    std::string token;

    builder_.start_expression ();

    while (!input.eof ())
    {

        input >> token;

        if (token == "+")
        {
            builder_.build_add_operator ();
        }
        else if (token == "-")
        {
            builder_.build_subtract_operator ();
        }
        else if (token == "*")
        {
            builder_.build_multiplication_operator ();
        }
        else if (token == "/")
        {
            builder_.build_division_operator ();
        }
        else if (token == "%")
        {
            builder_.build_modulus_operator ();
        }
        else if (token == "(")
        {
            builder_.build_open_parenthesis ();
        }
        else if (token == ")")
        {
            builder_.build_close_parenthesis ();
        }
        else // token == *Number* 
        {
            int number = stoi (token);
            builder_.build_number (number);
        }
    }

    // Return finished tree
    return builder_.get_expression ();
}

//
// evaluate (Expr_Node *)
//
int Calculator::evaluate (Expr_Node * tree)
{
    // Confirm tree is valid and evaluate it
    // delete tree after finished
    if (tree)
    {
        tree->accept (eval_);
        
        delete tree;
        
        return eval_.result ();
    }
    else
    {
        throw std::runtime_error ("No Expression");
    }
}

//
// run
//
void Calculator::run (void)
{
    // Start a loop for the user to enter problems
    // solve the problems and print the answer
    // keep going till user enter "QUIT"
    Expr_Node * tree;
    bool keep_going = true;
    std::string equation;
    while (keep_going)
    {
        try
        {
            std::cin.clear ();
            tree = nullptr;

            std::cout << "Enter a problem: " << std::endl;
            getline (std::cin , equation);

            if (equation != "QUIT")
            {
                tree = this->infix_to_tree (equation);

                int res = this->evaluate (tree);

                std::cout << "= " << res << std::endl;
            }
            else
            {
                keep_going = false;
            }
        }
        catch(const std::exception & e)
        {
            if (tree)
            {
                delete tree;
            }
            std::cout << e.what () << '\n';
        }
        
    }
}