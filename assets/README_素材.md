# 素材清单（Shooter 项目）

> 来源：`E:\素材\CraftPix出品2D游戏素材资产2026年度合集`（CraftPix 免费素材，可用于商业游戏，**不可把原始素材二次分发/转卖**）
> 整理日期：2026-11-11

---

## 一、目录结构

```
assets/
├── enemies/
│   ├── defense/        4 种敌人，48×48，3 方向（D/S/U）
│   │   ├── enemy1/     骷髅/僵尸
│   │   ├── enemy2/     红衣强盗
│   │   ├── enemy3/     绿衣兵 + Arrow/（箭矢 27 帧）
│   │   └── enemy4/     举盾兵 + Boom1~3（爆炸 8 帧）
│   └── elite/          3 种精英怪，96×96
│       ├── enemy1/     高个骷髅
│       ├── enemy2/     弓箭手
│       └── enemy3/     机械怪 + Projectile1/2
├── player/pixel/       2 个像素主角，32×32
│   ├── hero1/          绿衣剑士
│   └── hero3/          紫衣法师
├── fx/
│   ├── smoke/          烟（48×48，4 帧 × 多组）
│   ├── blood/          血（48×48，4 帧 × 多组）
│   ├── sparks/         火花（48×48，4 帧 × 多组）
│   ├── particles/      粒子（48×48，4 帧 × 多组）
│   ├── smoke_big/      大烟雾（128×128，10 张单帧）
│   ├── misc/           Arrow / Fireball / Shadow / 三种血
├── tiles/
│   ├── village/        32×32 地面 + 石头/装饰/箱子 + 动态物件
│   └── dungeon/        地牢图块（1 Tiles / 2 Objects / 3 Animated objects）
├── ui/pixel/           像素 UI：interface / buttons / bars
└── licenses/           各素材包的许可证原文
```

原来的 `manBlue_*.png`、`weapon_*.png`、`zoimbie1_hold.png` 原封未动。

---

## 二、帧尺寸速查

| 文件 | 整图 | 单帧 | 帧数 |
|---|---|---|---|
| `enemies/defense/enemyN/{D,S,U}_{Walk,Attack,Death}.png` | 288×48 | 48×48 | 6 |
| `enemies/defense/enemy4/Boom1~3.png` | 384×48 | 48×48 | 8 |
| `enemies/defense/enemy3/Arrow/*.png` | 3×14 | 3×14 | 27 张单帧 |
| `enemies/elite/enemyN/{D,S,U}_{Run,Attack,Death,Special}.png` | 576×96 | 96×96 | 6 |
| `enemies/elite/enemy3/{D,S,U}_Fly.png` | 576×96 | 96×96 | 6 |
| `player/pixel/heroN/D_Walk.png` | 192×32 | 32×32 | 6 |
| `player/pixel/heroN/S_Attack.png` | 128×32 | 32×32 | 4 |
| `player/pixel/heroN/D_Death.png` | 256×32 | 32×32 | 8 |
| `fx/{smoke,blood,sparks,particles}/N.png` | 192×48 | 48×48 | 4 |
| `fx/smoke_big/smoke2_*.png` | 128×128 | 128×128 | 10 张单帧 |
| `tiles/village/tiles/FieldsTile_NN.png` | 32×32 | 32×32 | — |
| `tiles/village/tiles/FieldsTileset.png` | 256×256 | 32×32 | 8×8 图集 |

---

## 三、命名规则

- `D_` = 朝下（down），`S_` = 朝侧面（side，配合水平翻转），`U_` = 朝上（up）
- `Walk / Run` 走/跑，`Attack` 攻击，`Death` 死亡，`Hurt` 受击，`Idle` 待机，`Special / Fly` 特殊动作
- 所有 `D_/S_/U_` 文件都是**横向 sprite sheet**，从左往右切帧

---

## 四、优先级（先用哪个）

1. **`fx/` —— 立刻能用。** 打中喷血、死亡爆炸、开枪冒烟，完全不用改旋转逻辑，`DrawTexturePro` 切帧就行。
2. **`tiles/village/` —— 铺地板**，把白背景换掉。
3. **`enemies/defense/` —— 48×48，尺寸最接近现在的 40px 角色。** 但它是 3/4 视角人形，**不能直接 rotation**，得改成"按移动方向选 D/S/U 帧 + 左右翻转"。
4. **`player/pixel/` —— 同上**，且换主角会整体改画风。
5. **`ui/pixel/` —— 血条 / 按钮**，做 HUD 时再用。

---

## 五、风格提醒（重要）

当前主角是 **Kenney 扁平矢量**（manBlue 33×43），这批素材是 **像素画**（48×48）。混用会"一个清晰、一个马赛克"。

两条路：

- **A（推荐先走）**：主角和僵尸保持现状，像素素材只做**特效 + 地面**。零风格冲突，立刻提升手感。
- **B（彻底切像素）**：主角换 `player/pixel/hero1`，敌人换 `enemies/defense`，地面换 `tiles/`，特效换 `fx/`。视觉统一，但要先写"方向帧"逻辑，因为像素人形不能靠旋转。

---

## 六、raylib 加载示例

```cpp
// 6 帧的 48×48 精灵表
Texture2D tex = LoadTexture("assets/enemies/defense/enemy1/D_Walk.png");

int frame = timer / 8 % 6;                       // 每帧 8 个游戏帧
Rectangle src = { frame * 48.0f, 0, 48.0f, 48.0f };
Rectangle dst = { x, y, 48, 48 };
Vector2 origin = { 24, 24 };
DrawTexturePro(tex, src, dst, origin, rotation, WHITE);
```

> `fx` 的第 1 帧（`1.png`、`smoke2_1.png`）可能是空的，从第 2 帧开始才有内容。

---

## 七、注意

- CMake 的 `POST_BUILD` 会把整个 `assets` 目录复制到 build 目录，**加完文件重新编译即可生效**，不用改 CMakeLists。
- 素材包里带了 `.psd` / `.eps` / `.ai` 源文件，我没拷，只用 PNG。
- 许可证在 `assets/licenses/`，商用前自己扫一眼。
