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

	return 1;
}

int get_col_num(char separation, char *input_file_name){
	FILE *fp;
	char c;
	int col_num;

	if ((fp = fopen(input_file_name, "r")) == NULL){
		printf("ファイルオープン失敗\n");
		exit(1);
	}

	col_num = 0;
	for (;;){
		c = fgetc(fp);
		if (c == EOF || c == '\n') break;
		if (c == separation){
			col_num++;
		}
	}

	fclose(fp);

	return col_num + 1;
}

void convert(int col_num, char separation, char *format, char *input_file_name, char *output_file_name){
	FILE *fi, *fo;
	char c;
	int i;

	if ((fi = fopen(input_file_name, "r")) == NULL){
		printf("ファイルオープン失敗\n");
		exit(1);
	}
	if ((fo = fopen(output_file_name, "a")) == NULL){
		printf("ファイル作成失敗\n");
		exit(1);
	}

	fprintf(fo, "\\begin{tabular}{");
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

	fclose(fi);
	fclose(fo);
}