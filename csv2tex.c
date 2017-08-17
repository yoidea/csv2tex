#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "convert.h"
#include "generate.h"
#include "help.h"

#define MAX_CHAR 100 // 最大文字列長

int main(int argc, char **argv){
	char option, separation;
	char caption[MAX_CHAR];
	char format[MAX_CHAR];
	char label[MAX_CHAR];
	char place[5];
	char input_file_name[MAX_CHAR];
	char output_file_name[MAX_CHAR];
	int col_num;
	FILE *fi, *fo;
	// 初期化、初期値代入
	opterr = 0;
	separation = ',';
	strcpy(caption, "");
	strcpy(format, "thesis");
	strcpy(label, "");
	strcpy(place, "h");
	strcpy(output_file_name, "output.txt");
	// オプション、引数取得
	while ((option = getopt(argc, argv, "CSThc:f:l:p:")) != -1){
		switch (option){
			case 'C':
				separation = ',';
				break;
			case 'S':
				separation = ' ';
				break;
			case 'T':
				separation = '\t';
				break;
			case 'c':
				strcpy(caption, optarg);
				break;
			case 'f':
				strcpy(format, optarg);
				break;
			case 'h':
				help(argv[0]);
				return 0;
			case 'l':
				strcpy(label, optarg);
				break;
			case 'p':
				strcpy(place, optarg);
				break;
			default:
				printf("オプションエラー\n");
				error(argv[0]);
				exit(1);
		}
	}
	// 引数チェック
	if (argc - optind < 1 || argc - optind > 2){
		error(argv[0]);
		exit(1);
	}
	if (check_format(format)){
		printf("フォーマット\"%s\"は存在しません\n", format);
		error(argv[0]);
		exit(1);
	}
	// ファイル名を取得
	strcpy(input_file_name, argv[optind]);
	optind++;
	if (optind > argc - 1){
		// 出力先指定がなければoutput.txtとする
		strcpy(output_file_name, "output.txt");
	} else {
		strcpy(output_file_name, argv[optind]);
	}
	// ファイルチェック
	if ((fi = fopen(input_file_name, "r")) == NULL){
		printf("%sを開けません\n", input_file_name);
		exit(1);
	}
	if ((fo = fopen(output_file_name, "w")) == NULL){
		printf("%sを作成できません\n", output_file_name);
		exit(1);
	}
	// フォーマットがdataならヘッダを出力しない
	if (strcmp(format, "data") != 0){
		gen_header(caption, label, place, fo);
	}
	// カラム数を取得する
	col_num = get_col_num(separation, fi);
	// csvを変換する
	convert(col_num, separation, format, fi, fo);
	// フォーマットがdataならフッタを出力しない
	if (strcmp(format, "data") != 0){
		gen_footer(fo);
	}
	fclose(fi);
	fclose(fo);
	return 0;
}