#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MALLOC_ERR 1<<4
#define MFREE_ERR  1<<5
#define FOPEN_ERR  1<<6
#define FCLOSE_ERR  1<<7

#define MALLOC(dest,type,size) \
  if((dest=(type)malloc(size))==NULL) return MALLOC_ERR;

#define MFREE(dest) \
  if(dest!=NULL){free(dest);}else{return MFREE_ERR;};

#define MNDUP(src,dest_type,dest,dest_size,dup_size) \
  MALLOC(dest,dest_type,dest_size); \
  memset(dest,0x0,dest_size);\
  memmove(dest,src,dup_size);

#define TRIM_LEFT   1
#define TRIM_RIGHT  2
#define TRIM_ALL    TRIM_LEFT|TRIM_RIGHT

int trim(char *str,char *list,int occur_cnt,char **ret,int mode){

  char *trim_list,*first,*last;
  int is_trim_c=0,trim_list_len=0,ret_len=0;
  int offset[2]={0};
  int trim_cnt=0;
  register int i=0;


  if(list!=NULL){

    trim_list=list;

  }else{

    MNDUP(" \n\t\0\x0B",char *,trim_list,7,6);

  }

  first=str;
  trim_list_len=strlen(trim_list);

  if((mode&TRIM_LEFT)==TRIM_LEFT){

    while((*str)!='\0'){

      for(i=0;trim_list_len>i;++i){
        
        if(((*str)==trim_list[i])){
          
          is_trim_c=1;
          ++trim_cnt;
          break;

        }else{

          is_trim_c=0;

        }

      }

      if(!is_trim_c) break;

      ++offset[0];
      ++str;

      if(occur_cnt!=0&&trim_cnt==occur_cnt) break;

    }

  }

  str=first+strlen(first)-1;
  last=str;
  trim_cnt=0;

  if((mode&TRIM_RIGHT)==TRIM_RIGHT){

    while((*str)!='\0'){

      for(i=0;trim_list_len>i;++i){
        
        if(((*str)==trim_list[i])){
          
          is_trim_c=1;
          ++trim_cnt;
          break;

        }else{

          is_trim_c=0;

        }

      }

      if(!is_trim_c) break;

      ++offset[1];
      --str;

      if(occur_cnt!=0&&trim_cnt==occur_cnt) break;

    }

  }

  ret_len=((last-offset[1])-(first+offset[0]))+1;
  MNDUP(first+offset[0],char *,(*ret),ret_len+1,ret_len);

  return 0;

}

int main(int argc,char **argv){

  char *str=" \n \r \n \t abcdefghijklmnopqrstuvwxyz \n   \t ";
  char *ret;

  printf("%s\n\n",str);

  trim(str,NULL,0,&ret,TRIM_RIGHT);
  printf("TRIM_RIGHT\n");
  printf("->%s<- %d\n\n",ret,strlen(ret));

  free(ret);

  trim(str,NULL,0,&ret,TRIM_LEFT);
  printf("TRIM_LEFT\n");
  printf("->%s<- %d\n",ret,strlen(ret));

  free(ret);

  trim(str,NULL,0,&ret,TRIM_ALL);
  printf("TRIM_ALL\n");
  printf("->%s<- %d\n\n",ret,strlen(ret));

  free(ret);

  trim(str,NULL,1,&ret,TRIM_ALL);
  printf("TRIM_ALL(just one occurence.)\n");
  printf("->%s<- %d\n\n",ret,strlen(ret));

  free(ret);

  trim(str,NULL,2,&ret,TRIM_ALL);
  printf("TRIM_ALL(just two occurence.)\n");
  printf("->%s<- %d\n\n",ret,strlen(ret));

  free(ret);

  return 0;

}
