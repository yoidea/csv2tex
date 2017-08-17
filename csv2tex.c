#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "convert.h"
#include "help.h"

#define MAX_CHAR 100

int main(int argc, char **argv){
	char option, separation;
	char caption[MAX_CHAR];
	char format[MAX_CHAR];
	char label[MAX_CHAR];
	char place[5];
	char input_file_name[MAX_CHAR];
	char output_file_name[MAX_CHAR];

	opterr = 0;
	separation = ',';
	strcpy(caption, "");
	strcpy(format, "thesis");
	strcpy(label, "");
	strcpy(place, "h");
	strcpy(output_file_name, "output.txt");

	while ((option = getopt(argc, argv, "CSThc:f:l:p:")) != -1){
		switch (option){
			case 'C':
				printf("カンマ区切り\n");
				separation = ',';
				break;
			case 'S':
				printf("スペース区切り\n");
				separation = ' ';
				break;
			case 'T':
				printf("タブ区切り\n");
				separation = '\t';
				break;
			case 'c':
				printf("Caption : %s\n", optarg);
				strcpy(caption, optarg);
				break;
			case 'f':
				printf("Format : %s\n", optarg);
				strcpy(format, optarg);
				break;
			case 'h':
				help(argv[0]);
				return 0;
			case 'l':
				printf("Label : %s\n", optarg);
				strcpy(label, optarg);
				break;
			case 'p':
				printf("Place : %s\n", optarg);
				strcpy(place, optarg);
				break;
			default:
				printf("オプションが不適切\n");
				error(argv[0]);
				exit(1);
		}
	}
	if (argc - optind < 1 || argc - optind > 2){
		printf("引数が不適切\n");
		error(argv[0]);
		exit(1);
	}
	printf("arg%d : %s\n", optind, argv[optind]);
	strcpy(input_file_name, argv[optind]);
	optind++;
	if (optind > argc - 1){
		printf("output指定なし\n");
	} else {
		printf("arg%d : %s\n", optind, argv[optind]);
		strcpy(output_file_name, argv[optind]);
	}
	printf("%lu %lu %lu %lu\n", strlen(caption), strlen(format), strlen(label), strlen(place));
	convert(separation, caption, format, label, place, input_file_name, output_file_name);
	
	return 0;
}