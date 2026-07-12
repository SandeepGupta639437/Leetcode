class Solution {
public:
    void solve1(int m,int n,vector<string>& v ){
        for(int i=0;i<n;i++){
            v[0][i] ='.';
        }
        for(int i=0;i<m;i++){
            v[i][n-1] = '.';
        }
    }
    void obs(int m,int n,vector<string>& v){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] != '.')v[i][j]='#';
            }
        }
    }
    vector<string> createGrid(int m, int n, int k) {
        if(m*n <= 4 && k>=3)return {};
        if((m*n<=2 || (m==1 || n==1)) && k> 1)return {};
        vector<string> v(m, string(n, '#'));
        if(m*n == 1 ){
            v[0][0] = '.';
            return v;
        }

        // if(m*n==2){
        //     if(m>n){
        //         v[0][0]='.';
        //         v[0][1]='.';
        //     }else{
        //         v[0][0]='.';
        //         v[1][0]='.';
        //     }
        //     return v;
        // }

        if(m==1 || n==1){
            if(m==1){
                for(int i=0;i<n;i++){
                    v[0][i] ='.';
                }
            }else{
                for(int i=0;i<m;i++){
                    v[i][0] ='.';
                }
            }

            return v;
        }

        if(m*n==4){
            if(k==1){
                v[0][0] = '.';
                v[1][1] = '.';
                v[0][1] ='.';
            }else{
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        v[i][j] = '.';
                    }
                }
            }
            obs(m,n,v);
            return v;
        }

        if(m*n==6){
            if(k==1){
                solve1(m,n,v);
            }else if(k==2){
                solve1(m,n,v);
                v[1][n-2] ='.';
            }else if(k==3){
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        v[i][j] = '.';
                    }
                }
            }else{
                return {};
            }
            obs(m,n,v);
            return v;
        }

        if(m*n == 9){
            if(k==1){
                solve1(m,n,v);
            }else if(k==2){
                solve1(m,n,v);
                v[1][n-2] ='.';
            }else if(k==3){
                solve1(m,n,v);
                v[1][n-2] ='.';
                v[2][n-2] ='.';
            }else{
                for(int i=0;i<n-1;i++){
                    v[0][i] = '.';
                }
                for(int i=0;i<n;i++){
                    v[1][i] = '.';
                }
                for(int i=1;i<n;i++){
                    v[2][i] = '.';
                }
            }
            obs(m,n,v);
            return v;
        }

        if(m==2 || n==2){
            if(m>n){
                if(k==1){
                    solve1(m,n,v);
                }else if(k==2){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                }else if(k==3){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[2][n-2] ='.';
                }
                else{
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[2][n-2] ='.';
                    v[3][n-2] ='.';
                }
            }else{
                if(k==1){
                    solve1(m,n,v);
                }else if(k==2){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                }else if(k==3){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[1][n-3] ='.';
                }
                else{
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[1][n-3] ='.';
                    v[1][n-4] ='.';
                }
            }
            obs(m,n,v);
            return v;
        }
        if(m==3 || n==3){
            if(m==3){
                if(k==1){
                    solve1(m,n,v);
                }else if(k==2){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                }else if(k==3){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[1][n-3] ='.';
                }
                else{
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[1][n-3] ='.';
                    v[1][n-4] ='.';
                }
            }else{
                if(k==1){
                    solve1(m,n,v);
                }else if(k==2){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                }else if(k==3){
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[2][n-2] ='.';
                }
                else{
                    solve1(m,n,v);
                    v[1][n-2] ='.';
                    v[2][n-2] ='.';
                    v[3][n-2] ='.';
                }
            }
        }

        if(m>3 && n>3){
            if(k==1){
                solve1(m,n,v);
            }else if(k==2){
                solve1(m,n,v);
                v[1][n-2] ='.';
            }else if(k==3){
                solve1(m,n,v);
                v[1][n-2] ='.';
                v[2][n-2] ='.';
            }else{
                solve1(m,n,v);
                v[1][n-2] ='.';
                v[2][n-2] ='.';
                v[3][n-2] = '.';
            }
            obs(m,n,v);
            return v;
        }

        return v;

    }
};