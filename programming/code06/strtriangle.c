void strtriangle(char *s) {
  printf("%s\n", s);
  if(*s == '\0') {
    // do nothing
  } else {
    strtriangle(s+1); 
  }
}
