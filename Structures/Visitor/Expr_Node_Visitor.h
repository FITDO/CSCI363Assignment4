#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

// Forward Declaration of objects
class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Number_Node;

/**
 * @class Expr_Node_Visitor
 * 
 * Template Class for the Visitor Pattern
 */
class Expr_Node_Visitor 
{ 
public: 

  // Destructor
  virtual ~Expr_Node_Visitor (void); 

  /**
   * Visit Addition Node
   * 
   * @param[in]        node       Addition_Node
   */
  virtual void Visit_Addition_Node (const Addition_Node & node) = 0; 

  /**
   * Visit Subtraction Node
   * 
   * @param[in]        node       Subtraction_Node
   */
  virtual void Visit_Subtraction_Node (const Subtraction_Node & node) = 0;

  /**
   * Visit Multiplication Node
   * 
   * @param[in]        node       Multiplication_Node
   */
  virtual void Visit_Multiplication_Node (const Multiplication_Node & node) = 0;

  /**
   * Visit Division Node
   * 
   * @param[in]        node       Division_Node
   */
  virtual void Visit_Division_Node (const Division_Node & node) = 0;

  /**
   * Visit Modulus Node
   * 
   * @param[in]        node       Modulus_Node
   */
  virtual void Visit_Modulus_Node (const Modulus_Node & node) = 0;

  /**
   * Visit Number Node
   * 
   * @param[in]        node       Number_Node
   */
  virtual void Visit_Number_Node (const Number_Node & node) = 0;

protected:

  // Default Constructor
  Expr_Node_Visitor (void);

}; 

#endif