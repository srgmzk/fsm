1. Project Goal
'''''''''''''''

o Programmable FSM Library


                  Three parts of
                  the this course
  Our Project                             
   +-------+   program the library     +-----+
   |  FSM  | <----------------------   | APP |
   |  lib  |   provide the input       |     |
   |       | <----------------------   |     |
   |       |   result                  |     |
   +-------+ ---------------------->   +-----+

   a). Program Library
      - Set of states
      - Transition tables
      - Final States, Initial State

   b). Provide the Input
      - Application needs to provide the input to Library
      - Library process the input
      
   c). Library provide results back to the application for use

o FSM Library is dumb, it don't know what and how to do, unless application teaches (programs) it

..code ::
   Examples:
        
        0/1          Input:   0 0 1 1 0
        /  \         Output:  1 1 0 0 1
   --> [ q0 ]                             Transition table
        \  /         +---------------+-------+--------+------------+
         1/0         | Current state | Input | Output | Next State |
                     +---------------+-------+--------+------------+
                     |     q0        |   0   |   1    |     q0     |
                     |     q0        |   1   |   0    |     q0     |
                     +---------------+-------+--------+------------+                         
                                                      \
                     Application Feeds this            \  
                     Complete information to Library    `---- FSM Library
                     
                     FSM Library execute the transation table and emit output

   Challenge: How to program the library!!
              Library can represent any FSM, depending on how it is programmed be the application
                     


2. Sample FSM
'''''''''''''

o Let us implement out simple FSM:
   
   > An FSM which accept input string on 0's and 1's with strict alternation
      - 0 -> accept
      - 1 -> accept
      - 01 -> accept
      - 10 -> accept
      - 101010101 or 01010101 -> accept
      - 101010100 -> reject
               ``
   > Assignment : Draw such a FSM and write it's transition table
   > We shall make use of this FSM as a sample example to design and implement the project concept

3. Assignment
'''''''''''''

      ??????


4. Project Outline
''''''''''''''''''

o Project in Four phases:
   > Phase 1: Basic Data Structures and APIs setup
   > Phase 2: Algorithm to execute FSM
   > Phase 3: How FSM would produce th output ?
   > Phase 4: Advance FSM

'''''''
PHASE 1
'''''''

o Data structures 

   > lib files: fsm.c and fsm.h
   > define a data structure *fsm_t* which represents a generic FSM
   > define a data structure *state_t* which represents a generic state
   > Every state has a transition table
   > A transition table is an array of transition table entries
   > We shall define a transition table entry data structure *tt_entry_t* which represents a single transition
      table entry
   
FSM Data structures and APIs setup
''''''''''''''''''''''''''''''''''

...

'''''''
PHASE 2
'''''''

FSM Execution Algorithm
'''''''''''''''''''''''

APIs - Public API to be used by the application to trigger FSM execution on input string shall be 

..code ::
      
   fsm_error_t
   execute_fsm(fsm_t *fsm, char *input_buffer, unsigned int size, fsm_bool_t *fsm_result);

Return: 
   FSM_NO_TRANSITION - If there is some error in parsing the input string, for example, next state of some
   transition entry is NULL (FSM is wrongly programmed be the application in phase 1)

   FSM_NO_ERROR - if Input String is Parsed succesfully (that does not mean input string is accepted)
                
               
fsm_result - The output Boolean variable, set to FSM_TRUE if the string is accepted, else FSM_FALSE

'''''''
PHASE 3
'''''''




