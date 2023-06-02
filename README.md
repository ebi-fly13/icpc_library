# ICPC Library
[![Actions Status](https://github.com/ebi-fly13/icpc_library/workflows/verify/badge.svg)](https://github.com/ebi-fly13/icpc_library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://ebi-fly13.github.io/icpc_library/)

チームAMATSUKAZEのICPCで用いるライブラリです。

## Codying style

ICPCではネット検索・ライブラリコピペが禁止であり、ライブラリは紙媒体で持って行く必要があります。よってライブラリには以下の要件をみたすものが望ましいです。

- 高速に写書できること
- 過度な高速化よりは、単純化し写し間違えを減らすこと
- ドキュメントがあり、チームメンバー全員が使えること

そのため次の3つのことを意識して作成されています。

- 過度な定数倍高速化は行わない
- template.hppにあるマクロなどを活用して書きやすくする
- 簡易的でもドキュメントを付ける
