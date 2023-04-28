

#include "Number_Node.h"

//
// Visit_Number_Node (const Number_Node &)
//
inline
void Print_Inorder_Expression::Visit_Number_Node (const Number_Node & node)
{
    std::cout << node.number () << " ";
}