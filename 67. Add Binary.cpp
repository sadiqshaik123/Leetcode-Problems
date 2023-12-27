class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int na = a.size(), nb = b.size(), n = max(na, nb), carry = 0;
        if (na > nb) {
            b = string(na - nb, '0') + b;
        } else {
            a = string(nb - na, '0') + a;
        }
        for (int i = n - 1; i >= 0; --i) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};
