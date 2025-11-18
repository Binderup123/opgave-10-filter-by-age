#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 100
#define DELIM "," // CSV delimiter

//  input and output fil navne.
char *ifile, *ofile;
unsigned filter_age_max;
FILE *istream, *ostream;

const char USAGE[] = 
    "\nUSAGE: %s [max-age] [ifile] [ofile]\n"
    "\n"
    "Filters hver linje fra en input til out basseret på argumenter\n"
    "\n"
    "Arguments:\n"
    "  max-alder   Max alder for at filtere\n"
    "  ifile     Input file (ikke nødvendig)\n"
    "  ofile     Output file (ikke nødvendig)\n";


void filter_stream(FILE *istream, FILE *ostream) {

  char line[LINE_MAX];
  char *fgets_return;
  char *name = malloc(LINE_MAX);
  char *age_str = malloc(LINE_MAX);
  size_t line_no = 0;

  while ((fgets_return = fgets(line, LINE_MAX, istream)) != NULL) {
    ++line_no;

    // Tom linje? (kun '\n' eller '\0')
        if (line[0] == '\n' || line[0] == '\0') {
            fprintf(stderr, "WARNING: linje %zu var tom.\n", line_no);
            continue;
        }

        // Split på komma: "navn,alder"
        char *name = strtok(line, DELIM);
        if (!name) {
            fprintf(stderr, "ERROR: linje %zu mangler navn.\n", line_no);
            continue;
        }

        char *age_str = strtok(NULL, DELIM);
        if (!age_str) {
            fprintf(stderr, "ERROR: ingen alder på linje %zu.\n", line_no);
            continue;
        }

    unsigned age;
   auto recognized_count = sscanf(age_str, "%d", &age);
    if (recognized_count == 1) {
      if (age <= filter_age_max) {

      if (age <= filter_age_max) 
      {
        fprintf(ostream, "\n%s, %d", name, age);
      }
    }
 } 
 else 
    {
      fprintf(stderr, "\nERROR: Age not recognized (failed to convert to a number)");
    }
  }
}
int main(int argc, char *argv[]) {
  switch (argc) {
  case 4:
    // max-age ifile ofile
    ofile = argv[3];
  case 3:
    // max-age ifile
    ifile = argv[2];
  case 2:
    // max-age
    if (!sscanf(argv[1], "%d", &filter_age_max)) {
      puts("First argument is not an age.");
      exit(EXIT_FAILURE);
    }
    break;
  default:
    printf(USAGE, argv[0]);
    return EXIT_SUCCESS;
  }

  if (ifile) {
    // Open `ifile` and assign it to `istream`
    // YOUR CODE HERE
    istream = fopen(ifile, "r");

    // Exit program with an error message if file cannot be opened
    // YOUR CODE HERE
  } else {
    // Set `istream` if no file provided
    // YOUR CODE HERE
    istream = stdin;
  }

  if (ofile) {
    // Open `ofile` and assign it to `ostream`
    // YOUR CODE HERE
ostream = fopen(ofile, "w");
    // Exit program with an error message if file cannot be opened
    // YOUR CODE HERE
  } else {
    // Set `ostream` if no file provided
    // YOUR CODE HERE
    ostream = stdout;
  }

  filter_stream(istream, ostream);
}
