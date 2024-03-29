/*  Main configuration
   VIM variables:
   vim600: noet sw=4 expandtab fdm=marker nu
   vim<600: noet sw=4 expandtab ts=4 nu
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOK_TOKEN_O 0x01
#define TOK_TOKEN_X 0x10

typedef struct tokened_st{
  int type;
  char *sta;
  char *end;
  struct tokened_st *next;
} tokened;

const char *token="~`!@#$%^&*()-_+=|\\{}[]:\"<>,.?/\n\t ";

int tokenrizer(const char *,const char *,tokened **);
int tokenrizer_free(tokened *tokened_head);

int main(int argc,char **argv){

  int size=0;
  tokened *tokened_head=NULL,*cur=NULL;
  const char *str="int tokenrizer(char *str,char *token,tokened **tokened_head){elice";
  char *buf=NULL;

  printf("TOKENS: >>%s<<\n",token);
  printf("STRINGS: >>%s<<\n",str);
  printf("TOKEN_O is a token else not a token\n");
  printf("\n");

  tokenrizer(str,token,&tokened_head);

  cur=tokened_head;

  while(cur!=NULL){

    size=(cur->end - cur->sta);
    buf=(char *)malloc(sizeof(char)*size+1);
    buf[size+1]='\0';
    memcpy(buf,cur->sta,size);

    printf("%s : '%s'\n",((cur->type==TOK_TOKEN_O) ? "TOKEN_O" : "TOKEN_X"),buf);

    cur=cur->next;

  }

  tokenrizer_free(tokened_head);

  return 0;

}

int tokenrizer(const char *str,const char *token,tokened **tokened_head){

  tokened *cur=NULL,*prev=NULL;
  char chr;
  int i=0,cnt=0;
  int token_len=0;
  char *last_token_occur=NULL;

  if(str==NULL){

    return 1;

  }

  if(token==NULL){

    return 2;

  }

  token_len=strlen(token);
  last_token_occur=(char *)str;

  while((chr=*(str+cnt))!='\0'){

    for(i=0;token_len>i;++i){

      if(chr==token[i]){

        if(str+cnt>last_token_occur){

          cur=(tokened *)malloc(sizeof(tokened));
          memset(cur,0x0,sizeof(tokened));
          cur->type=TOK_TOKEN_X;
          cur->sta=last_token_occur;
          cur->end=(char *)(str+cnt);

          if((*tokened_head)==NULL){

            (*tokened_head)=cur;

          }else{

            prev->next=cur;

          }

          prev=cur;

        }

        cur=(tokened *)malloc(sizeof(tokened));
        memset(cur,0x0,sizeof(tokened));
        cur->type=TOK_TOKEN_O;
        cur->sta=(char *)(str+cnt);
        cur->end=(char *)(str+cnt+1);

        if((*tokened_head)==NULL){

          (*tokened_head)=cur;

        }else{

          prev->next=cur;

        }

        prev=cur;

        last_token_occur=(char *)(str+cnt+1);

        break;

      }

    }

    ++cnt;

  }

  if(str+cnt>last_token_occur){

    cur=(tokened *)malloc(sizeof(tokened));
    memset(cur,0x0,sizeof(tokened));
    cur->type=TOK_TOKEN_X;
    cur->sta=last_token_occur;
    cur->end=(char *)(str+cnt);

    if((*tokened_head)==NULL){

      (*tokened_head)=cur;

    }else{

      prev->next=cur;

    }

    prev=cur;

  }

  return 0;

}

int tokenrizer_free(tokened *tokened_head){

  tokened *cur=NULL,*next=NULL;

  cur=tokened_head;

  while(cur!=NULL){

    next=cur->next;
    free(cur);
    cur=next;

  }

  return 0;

}
