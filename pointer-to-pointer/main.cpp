//#include <iostream>
#include <stdio.h>

struct S
{
  void (*callback)(S** _this);
};

void foo(S** s)
{
  printf("void foo(S**)\n");
//  std::cout << __PRETTY_FUNCTION__ << '\n';
}

void foo2(S** /*s*/)
{
  printf("void foo2(S**)\n");
//  std::cout << __PRETTY_FUNCTION__ << '\n';
}

int main()
{
  S s_callbacks { .callback = &foo };
  S s_callbacks_2 { .callback = &foo2 };
  
  S* ptrs[2] = {&s_callbacks, &s_callbacks_2};
  
  ptrs[0]->callback(ptrs); // foo
  ptrs[1]->callback(ptrs); // foo2

  return 0;
}
