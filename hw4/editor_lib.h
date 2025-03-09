#pragma once

typedef struct ll_text {
  char *text;
  struct ll_text *next;
} ll_text;

typedef struct ll_text_stack {
  ll_text *lines;
  struct ll_text_stack *next;
} ll_text_stack;

// functions for ll_text
ll_text *append_text(ll_text *list, char *text);

ll_text *insert_text(ll_text *list, char *text, int position);

ll_text *delete_text(ll_text *list, int position);

ll_text *replace_text(ll_text *list, char *text, int position);

ll_text *duplicate_ll_text(ll_text *list);

int ll_text_length(ll_text *list);

void save_to_file(ll_text *list, const char *filename);

// functions for ll_text_stack
ll_text_stack *new_stack_empty_text();

ll_text_stack *load_from_file(const char *filename);

// Push a new entry onto the stack that's an exact copy of the entry currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack);

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack);

// removes the entry that's currently at the top of the stack, frees all of its
// associated memory, and returns the new top of the stack.
ll_text_stack *pop_stack(ll_text_stack *stack);

// helpful text utility.
void chomp(char *s);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
