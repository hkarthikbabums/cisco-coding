# cisco-coding

1->4->5->+->5->NULL

The design is to come up with a linked list as above and treat the values before an operator as first operand by concatenating them and the values after the operator hit as send operand, then evaluate the first operand and second operand based on the received arithmetic operator.

145 concatenated to become the first operand

is the arithmetic operator 5 is concatenated second operand
Output of the code:

Equation: 145+5 

The result is: 150 

Result: 0 >> this is enum value for the success

Limitation: 

If the second operand was not provided then we should return an error, which is not done. Right now it returns the equation.

Equation: 145+ 

The result is: 145 

Result: 0

Haven't tried with larger numbers.
