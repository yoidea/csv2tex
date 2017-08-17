void gen_header(char *caption, char *label, char *place, char *output_file_name){
	FILE *fp;
	char c;

	if ((fp = fopen(output_file_name, "w")) == NULL){
		printf("ファイルオープン失敗\n");
		exit(1);
	}

	fprintf(fp, "\\begin{table}[%s]\n", place);
	if (strlen(caption) != 0){
		fprintf(fp, "\\caption{%s}\n", caption);
	}
	if (strlen(caption) != 0){
		fprintf(fp, "\\label{%s}\n", label);
	}
	fprintf(fp, "\\begin{center}\n");

	fclose(fp);
}

void gen_footer(char *output_file_name){
	FILE *fp;
	char c;

	if ((fp = fopen(output_file_name, "a")) == NULL){
		printf("ファイルオープン失敗\n");
		exit(1);
	}

	fprintf(fp, "\\end{center}\n");
	fprintf(fp, "\\end{table}\n");

	fclose(fp);
}