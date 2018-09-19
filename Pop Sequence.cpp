#include<stack>
#include<algorithm>
#include<cstdio>
#define maxn 1010
int a[maxn];
int M,N,K;
using namespace std;
bool Sequence(){
    int cap = M+1;
    int num=1;
    stack<int > sta;
    sta.push(0);
    int i=0;
    while(i<N){
        while(a[i]>sta.top() && sta.size()<cap)
            sta.push(num++);
        if(a[i] == sta.top()){
            i++;
            sta.pop();
        }
        else
            return false;
    }
    return true;

}
int main()
{
    scanf("%d %d %d",&M,&N,&K);
    for(int i=0; i<K; ++i){
        for(int k=0; k<N; ++k){
            scanf("%d",&a[k]);
        }
        if(Sequence()){
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
