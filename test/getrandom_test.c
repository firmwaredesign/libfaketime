#include <stdio.h>
#include <sys/random.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char *buf = calloc(100, 1);
  size_t buflen = 100;
  unsigned flags = GRND_NONBLOCK;

  fprintf(stdout, "Before getrandom:\n");
  for (int i=0; i < buflen; i++) { fprintf(stdout, "%hhu ", buf[i]); }
  fprintf(stdout, "\n");

  int result = getrandom(buf, buflen, flags);
  fprintf(stdout, "getrandom() result: %d\n", result);
  if (result == -1) perror("getrandom() unsuccessful");


  fprintf(stdout, "After getrandom:\n");
  for (int i=0; i < buflen; i++) { fprintf(stdout, "%hhu ", buf[i]); }
  fprintf(stdout, "\n");

  free(buf);
  return 0;
}
