# Functions

A function is a set of statements that takes input, does some specific computation, and produces output. The idea is to put some commonly or repeatedly done tasks together to make a function so that instead of writing the same code again and again for different inputs, we can call this function.
In simple terms, a function is a block of code that runs only when it is called.

_Formal Parameter_: A variable and its type as it appears in the prototype of the function or method.

_Actual Parameter_: The variable or expression corresponding to a formal parameter that appears in the function or method call in the calling environment.

**Parameter Passing Methods**

**Pass by Value:**
This method uses in-mode semantics. Changes made to formal parameters do not get transmitted back to the caller. Any modifications to the formal parameter variable inside the called function or method affect only the separate storage location and will not be reflected in the actual parameter in the calling environment.

**Pass by Address:**
This technique uses a pointer. In function we pass memory address (pointer) of a variable rather than passing the actual value of variable. This passing technique allows the function to access and modify the content at that particular memory location.

**Pass by Reference:**
When a variable is passed as a reference to a function, the address of the variable is stored in a pointer variable inside the function. Hence, the variable inside the function is an alias for the passed variable. Therefore, any operations performed on the variable inside the function will also be reflected in the calling function.

_important point about Call by Reference:_

One function cannot access the variables of another function directly, it can access indirectly (via pointers) but Call by Reference accessing variables directly because they uses alias for variables.
Call by Reference Function not becoming a separate function it has became a part of main function and there is only one activation record.

When the main function running when the CBR function starts variables becoming alias name and it's happening inside the same stack frame. So that CBR function is not a separate body of a function it has becoming part of the main function.

So the machine code is more like monolitic. Though the
sourse code is procedural or modular.

You can use the Call by Reference for the small functions but don't use it for heavy functions which are having loops and complex logic.
