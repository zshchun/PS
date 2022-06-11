typedef long long ll;
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
            long long i, j=0, k=0, a=0, b1=0, b2=0, c, ans = 0, third, total;
            total = accumulate(nums.begin(), nums.end(), 0);
            third = total / 3;

            c = total - nums[0];
            for (i=0;i<nums.size()-2;i++) {
                    a += nums[i];
                    if (a > third)
                            break;
                    while (a > b1 && i+j<nums.size()-1) {
                            j++;
                            b1 += nums[i+j];
                    }
                    while (b2+nums[i+k+1]<=c-nums[i+k+1] && i+k+1<nums.size()-1) {
                            k++;
                            b2 += nums[i+k];
                            c -= nums[i+k];
                    }
                    if (j == 0)
                            ans += k-j;
                    else if (k>=j)
                            ans += k-j+1;
                    if (j) {
                            j--;
                            b1 -= nums[i+1];
                    }

                    if (k) {
                            k--;
                            b2 -= nums[i+1];
                    }

            }
            return ans % 1000000007;
    }
};
