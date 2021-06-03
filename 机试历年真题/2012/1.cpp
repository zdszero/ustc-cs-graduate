#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  double a, b;
  char buf[128];
  FILE *infile = fopen("./string.in", "r");
  FILE *outfile = fopen("./string.out", "w");
  if (!infile || !outfile) exit(1);
  fscanf(infile, "%lf", &a);
  fscanf(infile, "%lf", &b);
  sprintf(buf, "%.10e", a+b);
  int i, j;
  for (i = 0; buf[i] != '\0'; i++)
    if (buf[i] == 'e')
      break;
  for (j = i-1; buf[j] == '0'; j--);
  for (int k = 0; k <= j; k++)
    fputc(buf[k], outfile);
  fputc('e', outfile);
  for (j = i+1; buf[j] != '\0'; j++)
    fputc(buf[j], outfile);
  return 0;
}
