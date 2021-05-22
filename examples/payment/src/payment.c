
#include "stdio.h"

const char regular[] = "regular";
const char estudante[] = "estudante";
const char aposentado[] = "aposentado";
const char vip[] = "vip";

static int strcmp(const char *s1, const char *s2)
{
  for(int i=0; i<20; i++)
  {
    if(s1[i]=='\0') break;
    if(s1[i]!=s2[i]) return 0;
  }
  return 1;
}

int payment(float value, char status[20])
{
  if(value >= 0.01f && value <= 99999.00f){
    if(strcmp(status,regular)) return 0;
    if(strcmp(status,estudante)) return 0;
    if(strcmp(status,aposentado)) return 0;
    if(strcmp(status,vip)) return 0;
    return 2;
  }
  return 1;
}
