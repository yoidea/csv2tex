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

Use tab for separation
```bash
csv2tex -T input.csv output.txt
```

Add a label
```bash
csv2tex -l label input.csv
```

Add a caption
```bash
csv2tex -c caption input.csv
```

Select a format
```bash
csv2tex -f format input.csv
```

Select a place
```bash
csv2tex -p htbp input.csv
```

`-f thesis`
```latex
\begin{table}[h]
\caption{caption}
\label{label}
\begin{center}
\begin{tabular}{l|l|l}
\hline \hline
A & B & C \\ \hline
1 & 2 & 3 \\
4 & 5 & 6 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

`-f grid`
```latex
\begin{table}[h]
\caption{caption}
\label{label}
\begin{center}
\begin{tabular}{|l|l|l|}
\hline
A & B & C \\ \hline
1 & 2 & 3 \\ \hline
4 & 5 & 6 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

`-f none`
```latex
\begin{table}[h]
\caption{caption}
\label{label}
\begin{center}
\begin{tabular}{lll}
A & B & C \\
1 & 2 & 3 \\
4 & 5 & 6 \\
\end{tabular}
\end{center}
\end{table}
```

`-f data`
```latex
A & B & C \\
1 & 2 & 3 \\
4 & 5 & 6 \\
```