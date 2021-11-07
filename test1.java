// 给定string 长度n， 0，1串，求连续子串个数，0和1个数一样
6， 100101
10，1001，100101，01，0101，10，01
public int CountSameZeroAndOne(String s){
    int n = s.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int zero = 0, one = 0;
        for(int j=i; j<n; j++){
            if(s.charAt(j) == "1"){
                one++;
            }
            if(s.charAt(j) == "0"){
                zero++;
            }
            if(j>0 && (j-i) % 2 == 0){
                if(zero == one){
                    count++;
                }
            }
        }
    }
    return count;
}