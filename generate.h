// ヘッダを出力する
void gen_header(char *caption, char *label, char *place, FILE *fp){
	char c;
	fprintf(fp, "\\begin{table}[%s]\n", place);
	if (strlen(caption) != 0){
		fprintf(fp, "\\caption{%s}\n", caption);
	}
	if (strlen(caption) != 0){
		fprintf(fp, "\\label{%s}\n", label);
	}
	fprintf(fp, "\\begin{center}\n");
}

// フッタを出力する
void gen_footer(FILE *fp){
	char c;
	fprintf(fp, "\\end{center}\n");
	fprintf(fp, "\\end{table}\n");
}