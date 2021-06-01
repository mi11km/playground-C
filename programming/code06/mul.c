int mul(int a, int b) {
  if(b == 0) {
    return 0;
  } else {
    return a + mul(a, b-1);
  }
}

int mul_with_accumulation_parameter(int a, int b, int accumulation_parameter) {
    if (b == 0) {
        return accumulation_parameter;
    } else {
        return mul_with_accumulation_parameter(a, b - 1, a + accumulation_parameter);
    }
}

int mul(int a, int b) {
    return mul_with_accumulation_parameter(a, b, 0);
}

