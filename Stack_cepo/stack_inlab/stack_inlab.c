#include <stdio.h>
#include <stdlib.h>

/*char형 스택 CharStack(헤더)
#ifndef ___CharStack
#define ___CharStack
*/

// 스택을 구현하는 구조체
typedef struct {
  int max; //스택 용량
  int ptr; //스택 포인터
  int *stk; //스택 첫 요소에 대한 포인터
} CharStack;

int Create(CharStack *s, int max);
int Push(CharStack *s, char x);
int Pop(CharStack *s, char *x);
int Peek(const CharStack *s, char *x);
void Clear(CharStack *s);
int Capacity(const CharStack *s);
int Size(const CharStack *s);
int IsFull(const CharStack *s);
int Search(const CharStack *s, char x);
void Print(const CharStack *s);

int main(){
  CharStack s;
  if(Create(&s,64) == -1){
    puts("스택 생성에 실패하였습니다.");
    return 1;
  }
  
  printf("1. Push                : +(element)");
  printf("\n2. Pop               : -- or (number)-");
  printf("\n3. Peek              : P");
  printf("\n4. Clear             : C");
  printf("\n5. Capacity          : A");
  printf("\n6. Size              : #");
  printf("\n7. IsFull            : F");
  printf("\n8. Search            : ?(element)");
  printf("\n9. Print             : L");
  printf("\n10. Quit             : Q");
  while(1){
    int x;
    printf("\ncommand: ");
    char command[20];
    gets(command);
    if (command[0] == 'Q')
      break;
    for (int i=0; command[i] !='\0';i++)
      if(command[i]=='+'){
        Push(&s,command[i+1]);
        i++;
      }
      else if(command[i]=='-'){
        if(Pop(&s,&x)==-1)
          puts("error");
        else
          printf("pop data is %c. \n",x);
      }
      else if(command[i]=='P'){
        if(Peek(&s,&x)==-1)
          puts("error");
        else
          printf("Peek data is %c\n",x);
      }
      else if(command[i]=='F'){
        if (IsFull(&s)==1)
          printf("True");
        else 
          printf("False");
      }
      else if(command[i]=='?'){
        if(Search(&s,command[i+1])==-1)
          printf("False\n");
        else 
          printf("TrueC\n");
      }
      else if(command[i]=='#'){
        printf("%d\n", Size(&s));
      }
      else if(command[i=='L']){
        Print(&s);
      }
      else if(command[i]=='C'){
        Clear(&s);
      }
    
  }
  
}



int Create(CharStack *s, int max)
{
  s->ptr = 0;
  if((s->stk = calloc(max,sizeof(char)))==NULL){
    s->max = 0;
    return -1;
  }
  s->max = max;
  return 0;
}

int Push(CharStack *s, char x)
{
  if(s->ptr >= s->max)
    return -1;
  s->stk[s->ptr++] = x;
  return 0;
}

int Pop(CharStack *s, char *x)
{
  if (s->ptr <=0)
    return -1;
  *x = s->stk[--s->ptr];
  return 0; 
}

int Peek(const CharStack *s, char *x)
{
  if (s->ptr <=0)
    return -1;
  *x = s->stk[s->ptr -1];
  return 0; 
}

void Clear(CharStack *s)
{
  printf("1");
  s-> ptr = 0;
}

int Capacity(const CharStack *s)
{
  return s->max;
}

int Size(const CharStack *s)
{
  return s->ptr;
}

int IsFull(const CharStack *s)
{
  return s->ptr >= s->max;
}

int Search(const CharStack *s, char x)
{
  int i;
  for(i = s->ptr -1;i>=0;i--)
    if(s->stk[i]==x)
      return 1;
  return -1;
}

void Print(const CharStack *s)
{
  int i;
  for (i=0;i<s->ptr;i++)
    printf("%c ",s->stk[i]);
  putchar('\n');
}
