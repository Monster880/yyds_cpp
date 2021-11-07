// 数组，找是否存在出现次数  >= length/3
public int findWordTimes(int[] nums){
    Arrays.sort(nums);
    int sum = 0;
    for(int i= nums.length/ 2; i<nums.length;){
        int left = findWordLeft(nums, nums[i]);
        int right = findWordRight(nums, nums[i]);
        if(right - left + 1 >= nums.length / 3){
            return nums[i];
        }
        i = i+right;
        i = i- left;
    }
}

public int findWordLeft(int[] nums, int temp){
    int left = 0, right = nums.length - 1;
    while(left < right){
        int mid = (left + right) >> 1;
        if(nums[mid] > temp){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

public int findWordRight(int[] nums, int temp){
    int left = 0, right = nums.length - 1;
    while(left < right){
        int mid = (left + right) >> 1;
        if(nums[mid] >= temp){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}