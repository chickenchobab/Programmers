import sys
from collections import deque
dx = [-1,0,1,0]
dy = [0,1,0,-1]
def bfs(x,y):
    visited = [[-1]*(w+2) for i in range(h+2)]
    visited[x][y] = 0
    queue = deque([(x,y)])
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h+2 and 0 <= ny < w+2 and arr[nx][ny] != '*' and visited[nx][ny] == -1:
                if arr[nx][ny] == '.' or arr[nx][ny] == '$':
                    visited[nx][ny] = visited[x][y]
                    queue.appendleft((nx,ny))
                elif arr[nx][ny] == '#':
                    visited[nx][ny] = visited[x][y] + 1
                    queue.append((nx,ny))
    return visited
t = int(input())
for _ in range(t):
    h,w = map(int,input().split())
    arr = [list('.'*(w+2))]
    for i in range(h):
        arr.append(list('.'+input().strip()+'.'))
    arr.append(list('.'*(w+2)))
    l = []
    for i in range(h+2):
        for j in range(w+2):
            if arr[i][j] == '$':
                l.append((i,j))
    a = bfs(l[0][0],l[0][1])
    b = bfs(l[1][0],l[1][1])
    c = bfs(0,0)
    ans = sys.maxsize
    for i in range(h+2):
        for j in range(w+2):
            if a[i][j] != -1 and b[i][j] != -1 and c[i][j] != -1:
                res = a[i][j] + b[i][j] + c[i][j]
                if arr[i][j] == '*':
                    continue
                if arr[i][j] == '#':
                    res -= 2
                ans = min(ans,res)
    print(ans)