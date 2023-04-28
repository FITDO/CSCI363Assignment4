#include "Expr_Tree_Builder.h"

//
// Expr_Tree_Builder
//
Expr_Tree_Builder::Expr_Tree_Builder (void)
:level_ (2) ,
 current_ (0) ,
 com_ ()
{
    // Allocate Space for Stacks
    for (int i = 0 ; i < 2 ; i++)
    {
        this->level_.set(i , new Stack<Operator_Expr_Node *>);
    }
}

//
// ~Expr_Tree_Builder
//
Expr_Tree_Builder::~Expr_Tree_Builder (void)
{
    // Unallocate all memory
    this->level_.resize( this->level_.max_size () );
    this->clear_memory ();
    for (int i = 0 ; i < this->level_.size () ; i++)
    {
        delete this->level_.get (i);
    }
}

//
// build_open_parenthesis
//
void Expr_Tree_Builder::build_open_parenthesis (void)
{
    // Increase the current level but make sure there is enough space
    // If not allocate it
    this->current_++;
    if (this->level_.size () <= this->current_)
    {
        level_.resize (this->current_ + 1);
        this->level_.set(this->current_ , new Stack<Operator_Expr_Node *>);
    }
} 

//
// build_close_parenthesis
//
void Expr_Tree_Builder::build_close_parenthesis (void)
{
    // First make sure we can go lower
    if (this->current_ > 0)
    {
        // Empty out the current level of Operators and assign their
        // Children if something goes wrong throw an error
        // If everything works return to lower level current_--
        while (!this->level_[current_]->is_empty ())
        {
            Operator_Expr_Node * n = this->level_[current_]->pop ();
            if (!n->set_children(this->com_))
            {
                this->clear_memory ();
                delete n;
                throw std::runtime_error ("Check Equation");
            }
            this->com_.push (n);
        }
        this->current_--;
    }
    else // this->current == 0
    {
        this->clear_memory ();
        throw std::runtime_error ("Check Parenthesis");
    }
}

//
// get_expression
//
Expr_Node * Expr_Tree_Builder::get_expression (void)
{
    // Perform a safety check to confirm method wasn't
    // called too early.
    if (this->current_ == 0)
    {
        // Empty out the current level of Operators and assign their
        // Children if something goes wrong throw an error
        while (!this->level_.get(0)->is_empty ())
        {
            Operator_Expr_Node * n = this->level_.get(0)->pop ();
            if (!n->set_children (this->com_))
            {
                this->clear_memory ();
                delete n;
                throw std::runtime_error ("Operator Error");
            }
            this->com_.push (n);
        }

        // Pop final node off the stack. This should be the last node
        // so confirm that that stack is empty is not throw error
        Expr_Node * expr = com_.pop ();

        if (this->com_.is_empty ())
        {
            this->clear_memory ();
            return expr;
        }
        else // !this->com_.is_empty ()
        {
            this->clear_memory ();
            delete expr;
            throw std::runtime_error ("Com Stack Not Empty");
        }

    }
    else // this->current_ != 0
    {
        throw std::runtime_error ("Check Parenthesis");
    }
}

//
// advance (Operator_Expr_Node *)
//
void Expr_Tree_Builder::advance (Operator_Expr_Node * node)
{
    // Keep going intil node was added to the level_
    // If level_ is empty add it
    // If top precedence is lower than node precedence add it
    // If both were false pop top and add children from com_ to top then push top to com_
    bool keep_looking = true;
    while (keep_looking)
    {
        if (this->level_.get(this->current_)->is_empty ())
        {
            this->level_.get(this->current_)->push (node);
            keep_looking = false;
        }
        else if (this->level_.get(this->current_)->top()->precedence () < node->precedence ())
        {
            this->level_.get(this->current_)->push (node);
            keep_looking = false;
        }
        else // top()->precedence () <= node->precdence ()
        {
            Operator_Expr_Node * n = this->level_[this->current_]->pop ();
            if (!n->set_children (this->com_))
            {
                this->clear_memory ();
                delete n;
                delete node;
                throw std::runtime_error ("Check Equation");
            }
            this->com_.push (n);
        }
    }
}

//
// clear_memory
//
void Expr_Tree_Builder::clear_memory (void)
{
    // Delete all left over nodes and reset
    for (int i = 0 ; i < this->level_.size () ; i++)
    {
        while (!this->level_.get(i)->is_empty ())
        {
            delete this->level_.get(i)->pop ();
        }
    }

    while (!this->com_.is_empty ())
    {
        delete this->com_.pop();
    }
    this->current_ = 0;
}