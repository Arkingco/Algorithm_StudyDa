#include <cstdio>

using namespace std;

int n, m;
bool check[9] = { false, };
int list[8];

void dfs(int cnt) {
    int i, k;
    if (cnt == m) {
        // 15650번, 15652번 : 오름차순 조건
        for (k = 0; k < m - 1; k++) if (list[k] > list[k+1]) break;
        if (k == m-1) {
            // 15649번 : 기본
            for (i = 0; i < m; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
        }
        return;
    }
    for (i = 1; i <= n; i++) {
        // 15649번 : 기본
        // 15651번, 15652번 : 같은 수를 여러번 골라도 되는 조건이라면 이 if 조건만 없애주면 된다.
        if (!check[i]) {
            check[i] = true;        
            list[cnt] = i;          
            dfs(cnt+1);             
            check[i] = false;
        }
    }

}

int main() {

    scanf("%d %d", &n, &m);
    
    dfs(0);
    return 0;
}