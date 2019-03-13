// Bhatta, Yubaraj
// yxb4124
// 2019-03-06
// C74767CF6

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getToken(FILE *fp);

regex_t STR;
regex_t FPP;
regex_t INT;

void processToken(char *token)
{
  int FPPP;
  int STRR;
  int INTT;
  FPPP = regexec(&FPP, token, (size_t)0, NULL, 0);
  STRR = regexec(&STR, token, (size_t)0, NULL, 0);
  INTT = regexec(&INT, token, (size_t)0, NULL, 0);

  if (FPPP != 1)
  {
    printf(">%s< matches FP.\n", token);
  }
  else if (STRR != 1)
  {
    printf(">%s< matches STR.\n", token);
  }
  else if (INTT != 1)
  {
    printf(">%s< matches INT.\n", token);
  }
  else
  {
    printf(">%s< does not match.\n", token);
  }
}
int main(int argc, char *argv[])
{
  if (regcomp(&FPP, "^[0-9]+[)][(][0-9]+$", REG_EXTENDED | REG_NOSUB) != 0)
  {
    printf("Error for FP\n");
    return (0);
  }
  if (regcomp(&STR, "^[|][A-Z0-9]*[+]$", REG_EXTENDED | REG_NOSUB) != 0)
  {
    printf("Error for STR\n");
    return (0);
  }
  if (regcomp(&INT, "^[#][0-9r-wR-W]+$", REG_EXTENDED | REG_NOSUB) != 0)
  {
    printf("Error for INT\n");
    return (0);
  }
  if (argc >1){
  printf("processing tokens from %s ...\n", argv[1]);

  FILE *fp = fopen(argv[1], "r");
  char *token = NULL;

  if (fp != NULL)
  {
    while (token = getToken(fp))
    {
      processToken(token);
      free(token);
    }

    fclose(fp);
  }
  else
  {
    printf("unable to open %s?\n", argv[1]);
  }
}
else{
  printf("No input file specified.\n");
}
}
#define MAX_TOKEN_SIZE (1024)

char *getToken(FILE *fp)
{
  char token[MAX_TOKEN_SIZE + 1];
  int i = 0;

  while (i < MAX_TOKEN_SIZE)
  {
    int ch = fgetc(fp);

    if (ch == EOF)
    {
      break;
    }

    if (isspace(ch))
    {
      if (i == 0)
      {
        continue;
      }
      break;
    }

    token[i++] = ch;
  }

  if (i == 0)
  {
    return NULL;
  }

  token[i] = '\0';

  return strdup(token);
}
