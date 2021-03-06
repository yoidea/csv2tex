# csv2tex
CSV形式のファイルからTeXテーブルを作成するコマンドラインツール。

## 動作環境
C言語がコンパイルできて、以下のライブラリが使える環境。
- stdio.h
- stdlib.h
- string.h
- unistd.h

## デモと使用法
input.csv
```csv
AAA,BBB,CCC
111,222,333
444,555,666
777,888,999
```

### 変換元ファイルだけ指定
```bash
csv2tex input.csv
```

output.txt
```latex
\begin{table}[h]
\begin{center}
\begin{tabular}{l|l|l}
\hline \hline
AAA & BBB & CCC \\ \hline
111 & 222 & 333 \\
444 & 555 & 666 \\
777 & 888 & 999 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

### 変換先ファイル名も指定
```bash
csv2tex input.csv output2.txt
```

output2.txt
```latex
\begin{table}[h]
\begin{center}
\begin{tabular}{l|l|l}
\hline \hline
AAA & BBB & CCC \\ \hline
111 & 222 & 333 \\
444 & 555 & 666 \\
777 & 888 & 999 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

### ラベル、キャプションを追加
```bash
csv2tex -c test -l table:test input.csv
```

output.txt
```latex
\begin{table}[h]
\caption{test}
\label{table:test}
\begin{center}
\begin{tabular}{l|l|l}
\hline \hline
AAA & BBB & CCC \\ \hline
111 & 222 & 333 \\
444 & 555 & 666 \\
777 & 888 & 999 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

### 配置場所を指定
```bash
csv2tex -p htbp input.csv
```

output.txt
```latex
\begin{table}[htbp]
\begin{center}
\begin{tabular}{l|l|l}
\hline \hline
AAA & BBB & CCC \\ \hline
111 & 222 & 333 \\
444 & 555 & 666 \\
777 & 888 & 999 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

### フォーマットを指定
```bash
csv2tex -f grid input.csv
```

output.txt
```latex
\begin{table}[h]
\begin{center}
\begin{tabular}{|l|l|l|}
\hline
AAA & BBB & CCC \\ \hline
111 & 222 & 333 \\ \hline
444 & 555 & 666 \\ \hline
777 & 888 & 999 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

```bash
csv2tex -f none input.txt
```

output.txt
```latex
\begin{table}[h]
\begin{center}
\begin{tabular}{lll}
AAA & BBB & CCC \\
111 & 222 & 333 \\
444 & 555 & 666 \\
777 & 888 & 999 \\
\end{tabular}
\end{center}
\end{table}
```

### 区切りにカンマ以外を使用
input2.csv
```csv
AAA	BBB	CCC
111	222	333
444	555	666
777	888	999
```

input3.csv
```csv
AAA BBB CCC
111 222 333
444 555 666
777 888 999
```

```bash
csv2tex -T input2.csv
```

```bash
csv2tex -S input3.csv
```

output.txt
```latex
\begin{table}[h]
\begin{center}
\begin{tabular}{l|l|l}
\hline \hline
AAA & BBB & CCC \\ \hline
111 & 222 & 333 \\
444 & 555 & 666 \\
777 & 888 & 999 \\ \hline
\end{tabular}
\end{center}
\end{table}
```

## インストール
`homebrew`を利用する。または、`make`を行う。もしくは`csv2tex.c`をコンパイルして実行する。

### homebrew (Mac only)
```bash
# install
brew tap yoidea/csv2tex
brew install csv2tex
# run
csv2tex -T -f grid input.csv
```

### make
```bash
# install
git clone https://github.com/yoidea/csv2tex.git
cd csv2tex/
make
# run
./csv2tex -T -f grid input.csv
```

### compile
```bash
# install
git clone https://github.com/yoidea/csv2tex.git
cd csv2tex/
gcc -o csv2tex csv2tex.c
# run
./csv2tex  -T -f grid input.csv
```