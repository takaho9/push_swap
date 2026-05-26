*This project has been created as part of the 42 curriculum by ttakemur, wezhou.*

# push_swap

## Description

`push_swap` は 2 つのスタック (`a`, `b`) と限られた操作セットだけで整数列を昇順ソートするプロジェクトです。本リポジトリはバイナリ `push_swap`（ソートに必要な操作列を標準出力に表示）と、ボーナスの `checker`（与えられた操作列がスタックを正しくソートするか検証）の 2 つを提供します。

許可されている操作: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`

## Instructions

### Build

```sh
make          # push_swap をビルド
make bonus    # checker をビルド
make re       # フルリビルド
make clean    # オブジェクトファイル削除
make fclean   # バイナリとオブジェクトを全削除
```

コンパイルフラグ: `cc -Wall -Wextra -Werror`

### Usage

```sh
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --medium "$ARG"
./push_swap --complex "$ARG"
./push_swap --adaptive "$ARG"      # デフォルト（戦略セレクタ省略時と同じ）
./push_swap --bench --adaptive "$ARG"   # 操作列は stdout、bench 情報は stderr
./push_swap "$ARG" | ./checker "$ARG"   # 結果検証
```

エラー時は `Error\n` を標準エラーに出力して終了します。エラー条件:
- 引数が整数でない
- `int` の範囲外
- 重複した値
- 不明なオプション、または戦略セレクタの重複指定

`--bench` 出力（stderr 行き）:
```
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0
```

## Algorithms

本実装は PDF で要求される 4 つの戦略を内蔵し、`--simple` / `--medium` / `--complex` / `--adaptive`（デフォルト）で切り替えます。disorder（順位比較で逆転しているペアの割合、PDF §VI.3.2 の擬似コード準拠）を `index_stack` 後の状態で測定し、`adaptive` 経路では以下のしきい値で動的に切り替えます。

| disorder | 選択戦略 | 計算量 |
|---|---|---|
| `< 0.2` | Simple | O(n²) |
| `0.2 ≤ d < 0.5` | Medium | O(n√n) |
| `≥ 0.5` | Complex | O(n log n) |

しきい値の根拠: ほぼ整列済み (`d < 0.2`) ではセレクションソート系の単純戦略が定数倍で勝つ。中間域では分割数 √n のチャンクソートが理論上限を満たしつつ実測でも安定。高 disorder ではバイナリラジックス（push_swap 操作モデル上 O(n log n)）が最少操作になる。

### Simple — Selection sort (O(n²))

`simple_sort.c` 単純に「index == i を探して pb、見つからなければ ra」を繰り返し、最後に `b` を全部 `pa` で戻す。最悪 2n²/2 ≈ n² 操作。

### Medium — Chunk sort (O(n√n))

`medium_sort.c` `a` を `√n` 個のチャンクに分割し、低い index のチャンクから順に `pb` で `b` に積む（各要素につき高々 1 回の `pb` ＋ チャンク跨ぎで生じる `ra`）。次に `b` の最大 index を探し、近い方向に `rb` / `rrb` で先頭に持ってきて `pa` で戻す。push_swap 操作モデル上 O(n × √n)。

### Complex — Binary radix sort (O(n log n))

`complex_sort.c` 最大 index のビット幅を `⌈log₂ size⌉` で求め、各ビットについて「bit が 0 の要素を `pb`、1 の要素を `ra`」→「`pa` で `b` を空にする」のパスを繰り返す。push_swap 操作モデル上 O(n × log n)。

### Adaptive — Dispatch by disorder

`push_swap.c::choose_strategy` `set_disorder` の結果に従い、上表のしきい値で内部的に Simple / Medium / Complex のいずれかを呼ぶ。bench での strategy 表示は「指定した戦略 / 実際に走った戦略の complexity」を併記する。

## Performance

PDF §VI.6 の Performance Benchmark に対する実測 (5 回平均、shuf で生成):

| 入力サイズ | 平均操作数 | 要求上限 | 状態 |
|---|---|---|---|
| 100 | ~1000 | 2000 (pass) / 1500 (good) / 700 (excellent) | ✅ good |
| 500 | ~7500 | 12000 (pass) / 8000 (good) / 5500 (excellent) | ✅ good |

## Resources

参考にしたリソース:
- 42 norminette ドキュメント (`v3.3.55`)
- LSD radix sort の概説 (Wikipedia, Knuth Vol.3)
- Chunk-based sort の各種実装例 (push_swap visualizer 系を含む既存リポジトリ調査)

AI（Claude Code）の利用:
- 仕様書 (PDF) との照合チェック、`norminette` 違反の指摘抽出、ベンチマーク測定スクリプトの叩き台作成
- バグの原因分析（無限ループや medium_sort の rotate 方向誤り）と修正提案のレビュー
- 実装ロジックそのものは学習者が記述・理解しており、AI 出力はレビュー対象として扱った

## Contributors

| login | 担当 |
|---|---|
| `ttakemur` | パース、`simple_sort`、`complex_sort`、bench 表示、Makefile、ディレクトリ整備 |
| `wezhou` | `medium_sort`、checker（bonus）、get_next_line、各 op の実装、エラー設計 |

両者がすべてのコードを読み、defense で説明できる状態。
