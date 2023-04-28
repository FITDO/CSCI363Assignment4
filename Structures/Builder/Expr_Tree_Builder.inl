

//
// builder_number (int)
//
inline
void Expr_Tree_Builder::build_number (int n)
{
    // Make a Number node and add it to to the com_ stack
    // since it has not children meaning it is complete
    this->com_.push (new Number_Node (n));
}

//
// start_expression
//
inline
void Expr_Tree_Builder::start_expression (void)
{
    this->clear_memory ();
}

//
// build_add_operator
//
inline
void Expr_Tree_Builder::build_add_operator (void)
{
    this->advance (new Addition_Node);
}

//
// build_subtract_operator
//
inline
void Expr_Tree_Builder::build_subtract_operator (void)
{
    this->advance (new Subtraction_Node);
}

//
// build_multiplication_operator
//
inline
void Expr_Tree_Builder::build_multiplication_operator (void)
{
    this->advance (new Multiplication_Node);
}

//
// build_division_operator
//
inline
void Expr_Tree_Builder::build_division_operator (void)
{
    this->advance (new Division_Node);
}

//
// build_modulus_operator
//
inline
void Expr_Tree_Builder::build_modulus_operator (void)
{
    this->advance (new Modulus_Node);
}