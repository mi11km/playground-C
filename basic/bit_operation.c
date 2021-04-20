void bit_operation() {
    unsigned char num = 0x49;
    printf("0x%x\n", num);     // 0x49: 01001001
    // or演算(|) ビットを立たせる
    num = num | 0x92;          // 0x92: 10010010
    printf("0x%x\n", num);     // 0xdb: 11011011
    // and演(&) ビットを落とす
    num = num & 0x6D;          // 0x6D: 01101101
    printf("0x%x\n", num);     // 0x49: 01001001

    // マスク処理: 特定ビット部分を抜き取りたいときに行う処理。作用させる値として抽出したいビット部分を「１」に設定
    // ex) 上位２桁（クラスコード）を取り出してそれが 10 ならクラスC
    unsigned char student = 0x98;    // 0x98: 10011011
    if ((student & 0xC0) == 0x80) {  // 0xC0: 11000000, 0x80: 10000000
        printf("クラスCの生徒\n");
    }

    // XOR演算は作用させる値に「１」を指定すると、対象となる変数の同一ビット部分の値を反転した値を作り出すことができる
    num = 0x9B;             // 0x9B: 10011011
    num = num ^ 0x56;       // 0x56: 01010110
    printf("0x%x\n", num);  // 0xCD: 11001101

    // 反転
    num = 0x9B;              // 0x9B: 10011011
    printf("0x%x\n", ~num);  // 0x64: 01100100

    /* シフト演算:
       １ビットの左シフト(<<)は値を２倍
       １ビットの右シフト(>>)は値を1/2倍 */

    // 論理シフト unsigned型の符号なしに対するシフト演算
    num = 0x9B;                  // 0x9B: 10011011
    printf("0x%x\n", num << 2);  // 0x6C: 01101100
    num = 0x9B;                  // 0x9B: 10011011
    printf("0x%x\n", num >> 2);  // 0x26: 00100110

    // 算術シフト　signed型の符号ありに対するシフト演算
    // 右シフトは符号ビットの値が補填される
    char n = 0x9B;                              // 0x9B: 10011011
    printf("0x%x\n", (unsigned char) n >> 2);    // 0xE6: 11100110

    n = 0x9B;                                 // 0x9B: 10011011
    printf("0x%x\n", (unsigned char) n << 2);  // 0x6C: 01101100
}

// binを2進数8桁で標準出力する
void printBin(unsigned char bin) {
    for (int i = 7; i >= 0; i--) {
        // i+1桁目を右シフトで一番右に持ってきて、一番右以外をマスク処理で0にする
        printf("%d", (bin >> i) & 0x01);
    }
    printf("b\n");
}

unsigned char makeStudentID(unsigned char class, unsigned char number, unsigned char gender) {
    if (class > 3 || number > 31 || gender > 1) {
        printf("invalid argument");
        exit(1);
    }
    return (class & 0x03) << 6 | (number & 0x1F) << 1 | (gender & 0x01);
}

void printStudentID(unsigned char studentID) {
    printf("クラス：%d\n", studentID >> 6);
    printf("出席番号：%d\n", (studentID & 0x3F) >> 1);
    printf("性別：%d\n", studentID & 0x01);
}
