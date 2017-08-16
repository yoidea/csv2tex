# csv2tex
A CLI tool that convert csv files to tex table, and insert in tex files

## Demo
input.csv -> output.txt
```bash
csv2tex input.csv
```

input.csv -> output2.txt
```bash
csv2tex input.csv output2.txt
```

Use tab for space
```bash
csv2tex -T input.csv output.txt
```

Insert in tex files
```bash
csv2tex -T input.csv output.txt -l label
```

Specify an insert point
```bash
csv2tex -T input.csv output.txt -l label -c caption
```

```bash
csv2tex -T input.csv output.txt -l label -c caption -f format
```