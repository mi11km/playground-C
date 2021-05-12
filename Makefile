
.SILENT:  # 実行コマンド非表示にする
run: main
	./main

main: main.o compiler.o
	gcc -Wall -O2 -o main main.o compiler.o

main.o: main.c
	gcc -c main.c

compiler.o: compiler/compiler.c
	gcc -c compiler/compiler.c

.PHONY: clean  # ターゲット名と同じファイルがあっても大丈夫にする
clean:
	rm -f main.o compiler.o main