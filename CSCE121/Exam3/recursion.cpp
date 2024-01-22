
bool isPalindrome(int num) {
    // Base case: If the number becomes zero, it's a palindrome
    if (num < 10) {
        return true;
    } else{
        int lastDigit = num % 10;
        num = num / 10;
        int divisor = 1;
        while (num / divisor >= 10 || num / divisor <= -10) {
            divisor *= 10;
        }
        int firstDigit = num / divisor;
        if(firstDigit == lastDigit){ return isPalindrome(num%divisor); }
        else{ return false; }
    }
}