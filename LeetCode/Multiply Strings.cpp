class Solution {
private:
    string sum(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string result = "";
        int carry = 0, max_size = max(num1.size(), num2.size());

        for(int i=0; i < max_size; i++) {
            int digit1 = 0, digit2 = 0;

            if (i < num1.size())
                digit1 = num1[i] - '0';
            
            if (i < num2.size())
                digit2 = num2[i] - '0';

            int temp_sum = digit1 + digit2 + carry;
            int new_digit = temp_sum % 10;
            carry = temp_sum / 10;

            result.push_back(new_digit + '0');
        }

        if (carry > 0)
            result.push_back(carry + '0');

        reverse(result.begin(), result.end());
        return result;
    }

    string multiply_by_one_digit(string num, char digit) {
        reverse(num.begin(), num.end());

        string result = "";
        int carry = 0, multiplier = digit - '0';

        for(int i=0; i < num.size(); i++) {
            int current_digit = num[i] - '0';
            int temp_mult = current_digit * multiplier + carry;
            int new_digit = temp_mult % 10;
            carry = temp_mult / 10;

            result.push_back(new_digit + '0');
        }

        if (carry > 0)
            result.push_back(carry + '0');
        
        reverse(result.begin(), result.end());
        return result;
    }
public:
    string multiply(string num1, string num2) {
        string reversed_num1 = num1, reversed_num2 = num2;
        string added_zeros = "", result = "0";

        reverse(reversed_num1.begin(), reversed_num1.end());
        reverse(reversed_num2.begin(), reversed_num2.end());

        for(int i=0; i < num1.size(); i++) {
            string current_product = multiply_by_one_digit(num2, reversed_num1[i]);
            
            result = sum(current_product + added_zeros, result);

            added_zeros.push_back('0');
        }

        if (count(result.begin(), result.end(), '0') == result.size())
            return "0";

        return result;
    }
};