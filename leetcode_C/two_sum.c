#include <stdio.h>
#include <stdlib.h>

struct object{
    int val;
    int index;
};

static int compare(const void *a, const void *b){
    return ( (struct object *) a) ->val -((struct object *) b) ->val;
}

static int *twoSum(int *nums, int numsSize, int target){
    int i,j;
    struct object *objs = malloc(numsSize * sizeof(*objs));
    for(i = 0; i < numsSize; i++)
    {
       objs[i].val   = nums[i];
       objs[i].index = i; 
    }
    qsort(objs, numsSize, sizeof(*objs), compare);

    int count = 0;
    int *results = malloc(2 * sizeof(int));

    i = 0;
    j = numsSize - 1;
    while(i<j){
        int diff = target - objs[i].val;
        if (diff > objs[j].val){
            i++;
            //while(++i < j && objs[i].val == objs[i - 1].val){}
        }else if (diff < objs[j].val){
            j++;
            //while(--j > i && objs[j].val == objs[j + 1].val){}
        }else{
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }
    }return NULL;
}

int main(void)
{
    int nums[] = { 4, 5, 2, 9, 1, 2, 7, 9, 8, 1, 3, 2, 1, 5, 2};
    int count  = sizeof(nums) / sizeof(*nums);
    int target = 12;
    int *indexes = twoSum(nums, count, target);
    if (indexes != NULL){
        printf("%d %d\n", indexes[0], indexes[1]);
    }else
    {
       printf("Not found\n"); 
    }
    return 0;
}