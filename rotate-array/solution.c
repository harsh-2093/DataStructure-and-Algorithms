void rotate(int* nums, int numsSize, int d) {
     int n=numsSize;
        d=d%n;
        if (d==0)return;
        int* temp = (int*)malloc(d * sizeof(int));

        for(int i=0;i<d;i++)
        {
            temp[i]=nums[n-d+i];
        }

        for(int i=n-d-1;i>=0;i--)
        {
            nums[i+d]=nums[i];
        }
        int j=0;
        for(int i=0;i<d;i++)
        {
            nums[i]=temp[i];
        }
    
}