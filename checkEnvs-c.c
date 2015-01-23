#include <stdio.h>
#include <stdlib.h>

int main ()
{
  char *foo, *bar;

  foo = getenv("FOO");
  bar = getenv("BAR");

  printf ("FOO is: %s\t\t %p \n", foo, foo);
  printf ("BAR is: %s\t\t %p \n", bar, bar);

  printf(" FOO ==  BAR -> ");
  if(foo == bar) {
    printf("True\n");
  } else {
    printf("False\n");
  };
  return 0;
}
