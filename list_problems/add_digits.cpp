class Solution {
public:
    int addDigits(int num) {
        if(num >=0 && num <= 9) return num;
        return addDigits(num / 10 + num % 10);
    }
};
class Solution {
public:
    int addDigits(int num) {
	if(num < 10)
            return num;
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);	
    }
};
