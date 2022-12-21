#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enum for evaluation error
enum error
{
    E_SUCCESS = 0,
    E_FAILURE  = -1
};

typedef enum error;

// Structure for a node in the linked list
struct node {
  char value;
  struct node *next;
};

// Function to create a new node with a given value
struct node *create_node(char value) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

// Function to concatenate a string
char *concat_list(struct node *head) {
  char *buffer = malloc(256);
  int index = 0;
  struct node *current = head;
  while (current != NULL) {
    buffer[index++] = current->value;
    current = current->next;
  }
  buffer[index] = '\0';
  return buffer;
}

// Function to evaulate the operands with the operator
enum error evaluate(char *string)
{
  int i;
  int fo = 0;
  int so = 0;
  int result = 0; 
  char op = '+';  
  int num = 0; 
  
  for (i = 0; i < strlen(string); i++) {
    char c = string[i];
    if (c >= '0' && c <= '9') {  
      num = num * 10 + (c - '0'); 
    }
    else {  
      int fo = num;
      if (op == '+') {
        result += num;
      }
      else if (op == '-') {
        result -= num;
      }
      else if (op == '*') {
        result *= num;
      }
      else if (op == '/') {
        result /= num;
      }
      op = c;  
      num = 0;  
    }
  }
  
  so = num;

  if (!so)
  { 
      printf("No second operand present\n");
      return E_FAILURE;
  }

  // Apply the last operator to the result
  if (op == '+') {
    result += num;
  }
  else if (op == '-') {
    result -= num;
  }
  else if (op == '*') {
    result *= num;
  }
  else if (op == '/') {
    result /= num;
  }

  printf("The Success Value is: %d\n", result);
  if(result)
  {
    return E_SUCCESS;
  } else {
    return E_FAILURE;
  }
}

int main() {
    
  struct node *head = create_node('1');
  head->next = create_node('4');
  head->next->next  = create_node('5');
  head->next->next->next  = create_node('+');
  head->next->next->next->next = create_node('5');

  // Concatenate the elements of the linked list
  char *equation = concat_list(head);
  printf("Equation: %s\n", equation);

  // Evaluate the equation and print the result
  int result = evaluate(equation);
  printf("Result: %d\n", result);

  // Free the memory allocated for the linked list and the equation string
  free(equation);
  while (head != NULL) {
    struct node *temp = head->next;
    free(head);
    head = temp;
  }

  return 0;
}
