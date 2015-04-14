//150412 bisection

#include <iostream>
#include <vector>
using namespace std;
  
vector<long long> input;
long long n, m;
  
bool possible(long long q){
    long long sum=m;
    for(int i=0; i<m; i++)
        sum+=(q/input[i]);
  
//  printf("%lld\n", sum);
    return sum >= n;
}
  
void solve(){
    long long start=0, end=60000000000, sum, ret, mid;
    while( start < end ){
        mid = (start+end)/2;
        if(possible(mid)){
            ret=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
  
     
 
    while(1){
        sum=m;
        for(int i=0; i<m; i++)
            sum+=(ret/input[i]);
     
 
        if(sum == n){
            for(int i=m-1; i>=0; i--){
                if(ret%input[i]==0){
                    printf("%d\n", i+1);
                    return;
                }
            }
        }
        if(sum < n ){
            break;
        }
        ret--;
    }
    sum=m;
    for(int i=0; i<m; i++)
        sum+=(ret/input[i]);
 
 
 
    ret++;
    for(int i=0; i<m; i++){
        if(ret%input[i]==0){
            sum++;
            if(sum==n){
                printf("%d\n", i+1);
                return;
            }
        }
    }
    return ;
}
  
int main(){
  
    //freopen("input.txt", "r", stdin);
    scanf("%lld %lld", &n, &m);
    input=vector<long long>(m);
    for(int i=0; i<m; i++) scanf("%lld", &input[i]);
  
    if( n <= m){
        printf("%d\n", n);
    }
    else
        solve();
    return 0;
}