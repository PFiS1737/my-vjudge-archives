# my-sdust-oj-archives

## Requirements

- GNU GCC
- fish
- just
- xmake
- fzf (optional)

## Usage

```sh
# 创建源文件
#   -a 启用 Append Code 模式
#   -n 仅创建文件而不询问内容
#   -y 默认确定
# 输入时直接换行即可，ctrl-c 到下一个问题
just new [-any]

# NOTE: 应该总是仅编辑 ./src/__main__.c 文件

# 评判
# 首次运行需无参数使用 `just` 进行初始化
just judge

# 归档当前工作区
# 提问 Description 为会跟在 ID 后面一起组成文件名的短描述
#      Problem 为具体题干
just archive

# 检出一个归档
# 不提供 id 则调用 fzf 进行搜索
just checkout [id]
```
