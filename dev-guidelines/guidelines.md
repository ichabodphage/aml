# aml guidelines

## functions
### specific rules
- all functions detached from classes should be mostly pure and without side effects (except in the case of logging)
- for convience all individual functions should be declared in the lib header
- functions with side effects should avoid having any return type
    - runtime errors are prefered over integer types indicating the sucess of the process
- if a functions entire job is to modify an object passed via reference, it should be an instance method of that class
    - an exception can be made with openGL functions that modify structs by reference,
      in those cases the functions should be declared as static members of the class where the struct is used

### recomendations
- long processes are preferably abstracted into sub functions that are accessed by that one function
- openGL calls should be mostly restricted to classes rather than functions

## classes

### specific rules
- composition is prefered over inheratence
- classes should have a generalized purpouse and should avoid being used for specific implementations
- if an instance variable often has its value changed outside of the class, it should probably be public
    - before writing a getter or setter, be sure that the variable actually needs one for the class to work properly
    - instance variables that are dynamically allocated are an exception to this rule, they should be private for
      the sake of the object correctly managing its lifetime. getters and setters are ok for these variables.

