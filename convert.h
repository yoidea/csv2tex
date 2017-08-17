// フォーマットが存在するか確認する
int check_format(char *format){
	if (strcmp(format, "thesis") == 0){
		return 0;
	} else if (strcmp(format, "grid") == 0){
		return 0;
	} else if (strcmp(format, "none") == 0){
		return 0;
	} else if (strcmp(format, "data") == 0){
		return 0;
	}
	// すべて該当しなければtrue
	return 1;
}

// カラム数を取得する
int get_col_num(char separation, FILE *fp){
	char c;
	int col_num;
	col_num = 0;
	for (;;){
		c = fgetc(fp);
		// 改行が見つかるまで走査
		if (c == EOF || c == '\n') break;
		// 区切りをカウント
		if (c == separation){
			col_num++;
		}
	}
	fseek(fp, 0, SEEK_SET);
	// 0からカウントしているため+1
	return col_num + 1;
}

// csvからtexテーブルに変換する
void convert(int col_num, char separation, char *format, FILE *fi, FILE *fo){
	char c;
	int i;
	fprintf(fo, "\\begin{tabular}{");
	// フォーマットに合わせて出力
	if (strcmp(format, "grid") == 0){
		fputc('|', fo);
	}
	for (i = 0; i < col_num - 1; i++){
		fputc('l', fo);
		if (strcmp(format, "thesis") == 0){
			fputc('|', fo);
		} else if (strcmp(format, "grid") == 0){
			fputc('|', fo);
		}
	}
	fputc('l', fo);
	if (strcmp(format, "grid") == 0){
		fputc('|', fo);
	}
	fprintf(fo, "}\n");
	if (strcmp(format, "thesis") == 0){
		fprintf(fo, "\\hline \\hline\n");
	} else if (strcmp(format, "grid") == 0){
		fprintf(fo, "\\hline\n");
	}
	// 1行目を変換
	for (;;){
		c = fgetc(fi);
		if (c == EOF || c == '\n') break;
		if (c == separation){
			fprintf(fo, " & ");
		} else {
			fputc(c, fo);
		}
	}
	if (strcmp(format, "thesis") == 0){
		fprintf(fo, " \\\\ \\hline\n");
	} else if (strcmp(format, "grid") == 0){
		fprintf(fo, " \\\\ \\hline\n");
	} else {
		fprintf(fo, " \\\\\n");
	}
	// 残りの行を変換
	for (;;){
		c = fgetc(fi);
		if (c == EOF) break;
		if (c == separation){
			fprintf(fo, " & ");
		} else if (c == '\n'){
			if (strcmp(format, "grid") == 0){
				fprintf(fo, " \\\\ \\hline\n");
			} else {
				fprintf(fo, " \\\\\n");
			}
		} else {
			fputc(c, fo);
		}
	}
	if (strcmp(format, "thesis") == 0 || strcmp(format, "grid") == 0){
		fprintf(fo, " \\\\ \\hline\n");
	} else {
		fprintf(fo, " \\\\\n");
	}
	fprintf(fo, "\\end{tabular}\n");
}