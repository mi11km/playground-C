// railmap2.h -- a railroad map (fields added)
#include <stdbool.h>
struct node { char *name; int num, edge[5], prev; bool visit; };
struct node map[] = {
  { "yokohama", 3, { 1, 3, 4 }, -1, false },    // 0
  { "kawasaki", 3, { 0, 2, 5 }, -1, false },    // 1
  { "shinagawa", 3, { 1, 3, 9 }, -1, false },   // 2
  { "osaki", 3, { 0, 2, 6 }, -1, false },       // 3
  { "hachiouji", 2, { 0, 5 }, -1, false },      // 4
  { "tachikawa", 3, { 1, 4, 6 }, -1, false },   // 5
  { "shinjuku", 4, { 3, 5, 7, 8 }, -1, false }, // 6
  { "ikebukuro", 3, { 6, 11, 12 }, -1, false }, // 7
  { "ochanomizu", 3, { 6, 9, 10 }, -1, false }, // 8
  { "tokyo", 3, { 2, 8, 10 } , -1, false },     // 9
  { "akihabara", 3, { 8, 9, 11 }, -1, false },  // 10
  { "tabata", 3, { 7, 10, 12 }, -1, false },    // 11
  { "akabane", 2, { 7, 11 }, -1, false },       // 12
};
