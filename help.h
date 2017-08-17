// 簡単な使用法を表示する
void error(char *name){
	printf("使用法: %s [-C | -T | -S] [[-c | -l | -f | -p] argment] source_file target_file\n", name);
	printf("詳細な使用法は\"%s -h\"と入力してください\n", name);
}

// 詳細な使用法を表示する
void help(char *name){
	printf("使用法: %s [-C | -T | -S] [[-c | -l | -f | -p] argment] source_file target_file\n", name);
	printf("  -C         : カンマ区切りデータ\n");
	printf("  -T         : タブ区切りデータ\n");
	printf("  -S         : スペース区切りデータ\n");
	printf("  -c caption : captionを付ける\n");
	printf("  -l label   : labelを付ける\n");
	printf("  -f format  : 出力形式を指定する\n");
	printf("      thesis 論文形式\n");
	printf("      grid   格子\n");
	printf("      none   線なし\n");
	printf("      data   データのみ\n");
	printf("  -p place   : placeを設定する\n");
	printf("      h  その場に出力\n");
	printf("      t  ページ上端に出力\n");
	printf("      b  ページ下端に出力\n");
	printf("      p  一面に出力\n");
}