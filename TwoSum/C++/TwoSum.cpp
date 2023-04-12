#include <cstdio>
#include <vector>

void print_result(std::vector<int> result){
    printf("%u, %u \n", result[0], result[1]);
}

std::vector<int> twosum (std::vector<int> nums, int target){
    short index = 0;
    while(index < nums.size()){
        for (short i = index + 1; i < nums.size(); i++)
        {
            if(nums[index] + nums[i] == target)
                return std::vector<int> {index, i};
        }
        index++;
    }
}


void test(){
    print_result(twosum(std::vector<int> {1,2,3,4,5}, 5));
    print_result(twosum(std::vector<int> {1,2,3,4,5}, 4));
    print_result(twosum(std::vector<int> {3,2,4}, 6));
}

int main(){
    test();
    return 0;
}
