void convert(char separation, char *caption, char *format, char *label, char *place, char *input_file_name, char *output_file_name){
	FILE *fi, *fo;
	char c;

	if ((fi = fopen(input_file_name, "r")) == NULL){
		printf("ファイルオープン失敗\n");
		exit(1);
	}
	if ((fo = fopen(output_file_name, "w")) == NULL){
		printf("ファイル作成失敗\n");
		exit(1);
	}

	for (;;){
		c = fgetc(fi);
		if (c == EOF) break;
		if (c == separation){
			fprintf(fo, " & ");
		} else if (c == '\n'){
			fprintf(fo, " \\\\\n");
		} else {
			fputc(c, fo);
		}
	}

	fclose(fi);
	fclose(fo);
}