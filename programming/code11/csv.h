// csv.h --- csv file read/write API.
struct csv { int num; char *cell[]; };
typedef struct csv *csvp;
int csv_read(char *fname, int limit, csvp arr[]);
void csv_write(char *fname, int size, csvp arr[]);

