

list0 = [['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.']]

for i in range(len(list0)):
    print(f'Black, what is the row you\'d like to place your stone? ', end = '')
    blackr = int(input())
    print(f'Black, what is the column you\'d like to place your stone? ', end='')
    blackc = int(input())

    list0[blackr][blackc] = 'O'

    while(list0[blackr][blackc] != '.'):
        print(f'There is already a stone placed at that location. Please retry.')
        print(f'Black, what is the row you\'d like to place your stone? ', end = '')
        blackr = int(input())
        print(f'Black, what is the column you\'d like to place your stone? ', end='')
        blackc = int(input())

    print(*list0[0], '\n', *list0[1], '\n', *list0[2], '\n', *list0[3], '\n', *list0[4],
        '\n', *list0[5], '\n', *list0[6], '\n', *list0[7], '\n', *list0[8], sep='')

    print(f'White, what is the row you\'d like to place your stone? ', end = '')
    whiter = int(input())
    print(f'White, what is the column you\'d like to place your stone? ', end='')
    whitec = int(input())

    list0[whiter][whitec] = 'o'

    while(list0[whiter][whitec] != '.'):
        print(f'There is already a stone placed at that location. Please retry.')
        print(f'White, what is the row you\'d like to place your stone? ', end = '')
        whiter = int(input())
        print(f'White, what is the column you\'d like to place your stone? ', end='')
        whitec = int(input())

    print(*list0[0], '\n', *list0[1], '\n', *list0[2], '\n', *list0[3], '\n', *list0[4],
        '\n', *list0[5], '\n', *list0[6], '\n', *list0[7], '\n', *list0[8], sep='')
