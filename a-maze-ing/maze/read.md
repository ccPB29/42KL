config.txt
   ↓
app/config_parser.py
读出 width / height / entry / exit / perfect / seed
   ↓
pattern_42.py
根据 width、height 算出哪些 cell 要封死成 “42”
   ↓
generator.py
拿着这些 42 坐标生成迷宫
→ 42 不参与通路
→ 其他所有 cell 必须连通
→ PERFECT=True：无环
→ PERFECT=False：制造多个环路
   ↓
solver.py
迷宫已经生成完，再找 entry → exit 的最短路径
   ↓
encoder.py
把每个 cell 的 N/E/S/W 墙编码成 0~F
   ↓
app/output.py
写进最终 maze.txt